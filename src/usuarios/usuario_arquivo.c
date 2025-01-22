#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"

#define ARQUIVO_USUARIOS "usuarios.dat"

// Função para salvar um usuário no arquivo
void salvar_usuario_arquivo(const Usuario *usuario) {
    FILE *arquivo = fopen(ARQUIVO_USUARIOS, "ab");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para salvar o usuário");
        exit(EXIT_FAILURE);
    }
    fwrite(usuario, sizeof(Usuario), 1, arquivo);
    fclose(arquivo);
}

// Função para carregar usuários do arquivo
void carregar_usuarios_arquivo(Usuario **usuarios, int *qtd_usuarios) {
    FILE *arquivo = fopen(ARQUIVO_USUARIOS, "rb");
    if (arquivo == NULL) {
        *usuarios = NULL;
        *qtd_usuarios = 0;
        return;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho_arquivo = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    *qtd_usuarios = tamanho_arquivo / sizeof(Usuario);
    *usuarios = malloc(tamanho_arquivo);

    if (*usuarios == NULL) {
        perror("Erro ao alocar memória para os usuários");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }

    fread(*usuarios, sizeof(Usuario), *qtd_usuarios, arquivo);
    fclose(arquivo);
}

void atualizar_usuario_arquivo(int id) {
    Usuario *usuarios = NULL;
    int qtd_usuarios = 0;

    carregar_usuarios_arquivo(&usuarios, &qtd_usuarios);
    if (!usuarios || qtd_usuarios == 0) {
        printf("Nenhum usuário encontrado.\n");
        free(usuarios);
        return;
    }

    for (int i = 0; i < qtd_usuarios; i++) {
        if (usuarios[i].id == id) {
            printf("Atualize os dados do usuário:\n");

            printf("Novo nome: ");
            fgets(usuarios[i].nome, sizeof(usuarios[i].nome), stdin);
            usuarios[i].nome[strcspn(usuarios[i].nome, "\n")] = '\0';

            printf("Novo email: ");
            fgets(usuarios[i].email, sizeof(usuarios[i].email), stdin);
            usuarios[i].email[strcspn(usuarios[i].email, "\n")] = '\0';

            printf("Nova senha: ");
            fgets(usuarios[i].senha, sizeof(usuarios[i].senha), stdin);
            usuarios[i].senha[strcspn(usuarios[i].senha, "\n")] = '\0';

            printf("O usuário é administrador? (1 - Sim, 0 - Não): ");
            int admin_input;
            scanf("%d", &admin_input);
            getchar(); // Limpar buffer
            usuarios[i].admin = (admin_input == 1);

            // Salvar alterações no arquivo
            FILE *arquivo = fopen(ARQUIVO_USUARIOS, "wb");
            if (arquivo == NULL) {
                perror("Erro ao abrir o arquivo para atualizar o usuário");
                free(usuarios);
                exit(EXIT_FAILURE);
            }
            fwrite(usuarios, sizeof(Usuario), qtd_usuarios, arquivo);
            fclose(arquivo);

            printf("Usuário atualizado com sucesso!\n");
            free(usuarios);
            return;
        }
    }

    printf("Usuário com ID %d não encontrado.\n", id);
    free(usuarios);
}

// Função para excluir um usuário do arquivo
void excluir_usuario_arquivo(int id) {
    Usuario *usuarios = NULL;
    int qtd_usuarios = 0;

    carregar_usuarios_arquivo(&usuarios, &qtd_usuarios);
    if (!usuarios || qtd_usuarios == 0) {
        printf("Nenhum usuário encontrado.\n");
        free(usuarios);
        return;
    }

    FILE *arquivo = fopen(ARQUIVO_USUARIOS, "wb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para excluir o usuário");
        free(usuarios);
        exit(EXIT_FAILURE);
    }

    int encontrou = 0;
    for (int i = 0; i < qtd_usuarios; i++) {
        if (usuarios[i].id != id) {
            fwrite(&usuarios[i], sizeof(Usuario), 1, arquivo);
        } else {
            encontrou = 1;
        }
    }

    fclose(arquivo);
    free(usuarios);

    if (encontrou) {
        printf("Usuário com ID %d excluído com sucesso!\n", id);
    } else {
        printf("Usuário com ID %d não encontrado.\n", id);
    }
}

// Função para obter o próximo ID de usuário
int obter_proximo_id_usuario(void) {
    FILE *arquivo = fopen(ARQUIVO_USUARIOS, "rb");
    if (arquivo == NULL) {
        return 1; // Primeiro ID
    }

    Usuario usuario;
    int maior_id = 0;

    while (fread(&usuario, sizeof(Usuario), 1, arquivo) > 0) {
        if (usuario.id > maior_id) {
            maior_id = usuario.id;
        }
    }

    fclose(arquivo);
    return maior_id + 1;
}

// Função para buscar um usuário no arquivo por ID
Usuario* buscar_usuario_arquivo(int id) {
    FILE *arquivo = fopen(ARQUIVO_USUARIOS, "rb");
    if (arquivo == NULL) {
        printf("Nenhum usuário cadastrado!\n");
        return NULL;
    }

    Usuario *usuario_encontrado = malloc(sizeof(Usuario));
    if (usuario_encontrado == NULL) {
        perror("Erro ao alocar memória para o usuário");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }

    while (fread(usuario_encontrado, sizeof(Usuario), 1, arquivo) > 0) {
        if (usuario_encontrado->id == id) {
            fclose(arquivo);
            return usuario_encontrado;
        }
    }

    free(usuario_encontrado);
    fclose(arquivo);
    return NULL;
}
