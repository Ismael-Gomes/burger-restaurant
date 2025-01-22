#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../validacoes/validacoes.h"
#include "usuarios.h"


void ler_id_codigo(int *id_codigo) {
    do {
        printf("Informe o código do produto (número inteiro): ");
        if (scanf("%d", id_codigo) != 1 || *id_codigo <= 0) {
            printf("Código inválido! Por favor, insira um número positivo.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
        } else {
            break;
        }
    } while (1);
    getchar(); // Remove o '\n' residual do buffer
}

// Função para ler o nome do produto
void ler_nome_produto(char *nome, size_t tamanho) {
    do {
        printf("///            Nome: ");
        fgets(nome, tamanho, stdin);
        remove_newline(nome); 
        if (!validarNome(nome)) { // Função de validação presumida em validacoes.h
            printf("///            Nome do produto é inválido! Deve ter pelo menos 3 caracteres.\n");
        }
    } while (!validarNome(nome)); // Repete até o nome ser válido
}

// Função para ler a quantidade em estoque
void ler_quantidade(int *quantidade) {
    char buffer[10];
    int valor_valido = 0;
    do {
        printf("///            Quantidade em estoque (número inteiro): ");
        fgets(buffer, sizeof(buffer), stdin);
        remove_newline(buffer);
        if (sscanf(buffer, "%d", quantidade) != 1 || *quantidade < 0) {
            printf("///            Quantidade inválida! Por favor, insira um número não negativo.\n");
        } else {
            valor_valido = 1;
        }
    } while (!valor_valido);
}

// Função para ler o valor do produto
void ler_valor_produto(char *valor, size_t tamanho) {
    double val;
    do {
        printf("///            Valor do produto (ex: 123.45): R$ ");
        fgets(valor, tamanho, stdin);
        remove_newline(valor);
        // Tentar interpretar o valor
        if (sscanf(valor, "%lf", &val) != 1) {
            printf("///            Formato inválido! Certifique-se de inserir um valor numérico válido.\n");
            continue;
        }
        // Verificar se o valor é positivo
        if (val < 0) {
            printf("///            Valor inválido! O valor deve ser maior ou igual a zero.\n");
            continue;
        }
        // Tudo está válido
        break;
    } while (1);
}