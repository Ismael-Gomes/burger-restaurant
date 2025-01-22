#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

#define ARQUIVO_PRODUTOS "produtos.dat"

void salvar_produto_arquivo(const Produto *produto) {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "ab");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para salvar o produto");
        exit(EXIT_FAILURE);
    }
    fwrite(produto, sizeof(Produto), 1, arquivo);
    fclose(arquivo);
}

void carregar_produtos_arquivo(Produto **produtos, int *qtd_produtos) {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "rb");
    if (arquivo == NULL) {
        *produtos = NULL;
        *qtd_produtos = 0;
        return;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho_arquivo = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    *qtd_produtos = tamanho_arquivo / sizeof(Produto);
    *produtos = malloc(tamanho_arquivo);

    if (*produtos == NULL) {
        perror("Erro ao alocar memória para os produtos");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }

    fread(*produtos, sizeof(Produto), *qtd_produtos, arquivo);
    fclose(arquivo);
}

void atualizar_produto_arquivo(int id_codigo) {
    Produto *produtos;
    int qtd_produtos;
    // Função para carregar os produtos
    carregar_produtos_arquivo(&produtos, &qtd_produtos);

    if (!produtos) {
        printf("Nenhum produto encontrado.\n");
        return;
    }

    for (int i = 0; i < qtd_produtos; i++) {
        if (produtos[i].id_codigo == id_codigo) {
            printf("Atualize os dados do produto:\n");
            printf("Novo nome: ");
            fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
            produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';

            printf("Novo preço (como número, será armazenado como string): ");
            fgets(produtos[i].valor, sizeof(produtos[i].valor), stdin);
            produtos[i].valor[strcspn(produtos[i].valor, "\n")] = '\0'; 

            float valor = atof(produtos[i].valor);  
            printf("Preço como float: %.2f\n", valor);

            FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "wb");
            if (arquivo == NULL) {
                perror("Erro ao abrir o arquivo para atualizar o produto");
                free(produtos);
                exit(EXIT_FAILURE);
            }
            fwrite(produtos, sizeof(Produto), qtd_produtos, arquivo);
            fclose(arquivo);

            printf("Produto atualizado com sucesso!\n");
            free(produtos);
            return;
        }
    }

    printf("Produto com ID %d não encontrado.\n", id_codigo);
    free(produtos);
}

void excluir_produto_arquivo(int id_codigo) {
    Produto *produtos;
    int qtd_produtos;
    carregar_produtos_arquivo(&produtos, &qtd_produtos);

    if (!produtos) {
        printf("Nenhum produto encontrado.\n");
        return;
    }

    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "wb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para excluir o produto");
        free(produtos);
        exit(EXIT_FAILURE);
    }

    int encontrou = 0;
    for (int i = 0; i < qtd_produtos; i++) {
        if (produtos[i].id_codigo != id_codigo) {
            fwrite(&produtos[i], sizeof(Produto), 1, arquivo);
        } else {
            encontrou = 1;
        }
    }

    fclose(arquivo);
    free(produtos);

    if (encontrou) {
        printf("Produto com ID %d excluído com sucesso!\n", id_codigo);
    } else {
        printf("Produto com ID %d não encontrado.\n", id_codigo);
    }
}

int obter_proximo_id_produto(void) {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "rb");
    if (arquivo == NULL) {
        return 1; 
    }

    Produto produto;
    int maior_id = 0;

    while (fread(&produto, sizeof(Produto), 1, arquivo) > 0) {
        if (produto.id_codigo > maior_id) {
            maior_id = produto.id_codigo;
        }
    }

    fclose(arquivo);
    return maior_id + 1;
}

Produto* buscar_produto_arquivo(int id_codigo) {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "rb");
    if (arquivo == NULL) {
        printf("Nenhum produto cadastrado!\n");
        return NULL;
    }

    Produto *produto_encontrado = malloc(sizeof(Produto));
    if (produto_encontrado == NULL) {
        perror("Erro ao alocar memória para o produto");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }

    while (fread(produto_encontrado, sizeof(Produto), 1, arquivo) > 0) {
        if (produto_encontrado->id_codigo == id_codigo) {
            fclose(arquivo);
            return produto_encontrado;
        }
    }

    free(produto_encontrado);
    fclose(arquivo);
    return NULL;
}
