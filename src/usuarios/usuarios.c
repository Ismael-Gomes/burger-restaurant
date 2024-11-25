#include <stdio.h>
#include <string.h>
#include "usuarios.h"
#include "validacoes.h"
#define ARQUIVO_USUARIOS "usuarios.dat"

void salvarUsuariosEmArquivo(Usuario usuarios[], int totalUsuarios) {
    FILE *arquivo = fopen(ARQUIVO_USUARIOS, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os usuários.\n");
        return;
    }

    fwrite(&totalUsuarios, sizeof(int), 1, arquivo); // Salva o total de usuários
    fwrite(usuarios, sizeof(Usuario), totalUsuarios, arquivo); // Salva os dados dos usuários

    fclose(arquivo);
    printf("Usuários salvos com sucesso!\n");
}

int carregarUsuariosDeArquivo(Usuario usuarios[]) {
    FILE *arquivo = fopen(ARQUIVO_USUARIOS, "rb");
    if (arquivo == NULL) {
        printf("Nenhum arquivo encontrado. Iniciando com dados padrão.\n");
        return 0;  
    }

    int totalUsuarios;
    fread(&totalUsuarios, sizeof(int), 1, arquivo); // Lê o total de usuários
    fread(usuarios, sizeof(Usuario), totalUsuarios, arquivo); // Lê os dados dos usuários

    fclose(arquivo);
    return totalUsuarios;  // MOStra o total de usuários
}
void cadastrarUsuario(Usuario usuarios[], int *totalUsuarios) {
    if (*totalUsuarios >= 10) {
        printf("Erro: Não há mais espaço para novos usuários.\n");
        return;
    }

    Usuario novoUsuario;
    novoUsuario.id = *totalUsuarios + 1;

    printf("Digite o nome do Usuário:\n");
    scanf(" %[^\n]%*c", novoUsuario.nome);
    if (!validarNome(novoUsuario.nome)) return;

    printf("Digite o email do Usuário:\n");
    scanf("%s", novoUsuario.email);
    if (!validarEmail(novoUsuario.email)) return;

    printf("Digite a senha do Usuário:\n");
    scanf("%s", novoUsuario.senha);
    if (!validarSenha(novoUsuario.senha)) return;

    novoUsuario.admin = false;
    usuarios[*totalUsuarios] = novoUsuario;
    (*totalUsuarios)++;

    printf("Usuário cadastrado com sucesso!\n");

    // Salva os usuários no arquivo após adicionar um novo
    salvarUsuariosEmArquivo(usuarios, *totalUsuarios);
}
