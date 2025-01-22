#include "relatorio_produtos.h"
#include "../produtos/produtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarArquivoProdutos() {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "ab");
    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo");
        exit(EXIT_FAILURE);
    }
    fclose(arquivo);
}

double listarRelatoriosProdutos() {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        exit(EXIT_FAILURE);
    }

    double total = 0;
    Produto entrada;

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Relatório Detalhado de Produtos = = = = =        ///\n");
    printf("///                                                                         ///\n");

    while (fread(&entrada, sizeof(Produto), 1, arquivo) > 0) {
        printf("ID: %d\n", entrada.id_codigo);
        printf("Nome: %s\n", entrada.nome);
        printf("Quantidade em Estoque: %d\n", entrada.quantidade_estoque);
        printf("Valor: R$ %s\n", entrada.valor);

        total += atof(entrada.valor);
        printf("-------------------------\n");
    }

    printf("///                                                                         ///\n");
    printf("///            Valor Total dos Produtos: R$ %.2f                          ///\n", total);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    fclose(arquivo);
    return total;
}

void menu_relatorio_produto(void) {
    int opcao;
    char criterio[100];

    do {
        system("clear||cls");
        printf("\n///////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = Relatório de Produtos = = = = = = = =          ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Exibir Todos os Produtos                                  ///\n");
        printf("///            2. Filtrar por Nome                                         ///\n");
        printf("///            3. Filtrar por Valor                                        ///\n");
        printf("///            4. Filtrar por Quantidade                                   ///\n");
        printf("///            0. Voltar ao Menu Anterior                                  ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                listarRelatoriosProdutos();
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 2:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe o Nome para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0';
                filtrar_produto_por_nome(criterio);
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 3:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe o Valor para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0';
                filtrar_produto_por_valor(criterio);
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 4:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe a Quantidade mínima de Estoque para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0';
                filtrar_produto_por_quantidade(criterio);
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 0:
                printf("\nRetornando ao Menu Anterior...\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
        }
    } while (opcao != 0);
}

void filtrar_produto_por_nome(const char *nomeFiltro) {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Produto entrada;
    int encontrado = 0;

    printf("Produtos (Filtrado por Nome: %s):\n", nomeFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Produto), 1, arquivo)) {
        if (strstr(entrada.nome, nomeFiltro)) {
            encontrado = 1;
            printf("ID: %d\n", entrada.id_codigo);
            printf("Nome: %s\n", entrada.nome);
            printf("Quantidade em Estoque: %d\n", entrada.quantidade_estoque);
            printf("Valor: R$ %s\n", entrada.valor);
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhum produto encontrado com o nome: %s\n", nomeFiltro);
    }

    fclose(arquivo);
}

void filtrar_produto_por_valor(const char *valorFiltro) {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Produto entrada;
    int encontrado = 0;

    printf("Produtos (Filtrado por Valor: %s):\n", valorFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Produto), 1, arquivo)) {
        if (strcmp(entrada.valor, valorFiltro) == 0) {
            encontrado = 1;
            printf("ID: %d\n", entrada.id_codigo);
            printf("Nome: %s\n", entrada.nome);
            printf("Quantidade em Estoque: %d\n", entrada.quantidade_estoque);
            printf("Valor: R$ %s\n", entrada.valor);
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhum produto encontrado com o valor: %s\n", valorFiltro);
    }

    fclose(arquivo);
}

void filtrar_produto_por_quantidade(const char *quantidadeFiltro) {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Produto entrada;
    int encontrado = 0;
    int quantidadeMinima = atoi(quantidadeFiltro);

    printf("Produtos (Filtrado por Quantidade em Estoque: %d):\n", quantidadeMinima);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Produto), 1, arquivo)) {
        if (entrada.quantidade_estoque >= quantidadeMinima) {
            encontrado = 1;
            printf("ID: %d\n", entrada.id_codigo);
            printf("Nome: %s\n", entrada.nome);
            printf("Quantidade em Estoque: %d\n", entrada.quantidade_estoque);
            printf("Valor: R$ %s\n", entrada.valor);
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhum produto encontrado com a quantidade mínima em estoque: %d\n", quantidadeMinima);
    }

    fclose(arquivo);
}
