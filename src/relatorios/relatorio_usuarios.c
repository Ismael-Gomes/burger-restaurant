#include "relatorio_usuarios.h"
#include "../usuarios/usuarios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarArquivoUsuarios() {
    FILE *arquivo = fopen(ARQUIVO_USUARIOS, "ab");
    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo");
        exit(EXIT_FAILURE);
    }
    fclose(arquivo);
}

void listarRelatoriosUsuarios() {
    FILE *arquivo = fopen(ARQUIVO_USUARIOS, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        exit(EXIT_FAILURE);
    }

    Usuario entrada;

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Relatório Detalhado de Usuários = = = = =        ///\n");
    printf("///                                                                         ///\n");

    while (fread(&entrada, sizeof(Usuario), 1, arquivo) > 0) {
        printf("ID: %d\n", entrada.id);
        printf("Nome: %s\n", entrada.nome);
        printf("Email: %s\n", entrada.email);
        printf("Tipo: %s\n", entrada.admin ? "Admin" : "Cliente");
        printf("-------------------------\n");
    }

    printf("///////////////////////////////////////////////////////////////////////////////\n");

    fclose(arquivo);
}

void menu_relatorio_usuario(void) {
    int opcao;
    char criterio[100];

    do {
        system("clear||cls");
        printf("\n///////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = Relatório de Usuários = = = = = = = =          ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Exibir Todos os Usuários                                  ///\n");
        printf("///            2. Filtrar por Nome                                         ///\n");
        printf("///            3. Filtrar por Email                                        ///\n");
        printf("///            4. Filtrar por Tipo (Admin/Cliente)                         ///\n");
        printf("///            0. Voltar ao Menu Anterior                                  ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                listarRelatoriosUsuarios();
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 2:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe o Nome para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0';
                filtrar_usuario_por_nome(criterio);
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 3:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe o Email para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0';
                filtrar_usuario_por_email(criterio);
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 4:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe o Tipo (Admin ou Cliente) para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0';
                filtrar_usuario_por_tipo(criterio);
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

void filtrar_usuario_por_nome(const char *nomeFiltro) {
    FILE *arquivo = fopen(ARQUIVO_USUARIOS, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Usuario entrada;
    int encontrado = 0;

    printf("Usuários (Filtrados por Nome: %s):\n", nomeFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Usuario), 1, arquivo)) {
        if (strstr(entrada.nome, nomeFiltro)) {
            encontrado = 1;
            printf("ID: %d\n", entrada.id);
            printf("Nome: %s\n", entrada.nome);
            printf("Email: %s\n", entrada.email);
            printf("Tipo: %s\n", entrada.admin ? "Admin" : "Cliente");
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhum usuário encontrado com o nome: %s\n", nomeFiltro);
    }

    fclose(arquivo);
}

void filtrar_usuario_por_email(const char *emailFiltro) {
    FILE *arquivo = fopen(ARQUIVO_USUARIOS, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Usuario entrada;
    int encontrado = 0;

    printf("Usuários (Filtrados por Email: %s):\n", emailFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Usuario), 1, arquivo)) {
        if (strstr(entrada.email, emailFiltro)) {
            encontrado = 1;
            printf("ID: %d\n", entrada.id);
            printf("Nome: %s\n", entrada.nome);
            printf("Email: %s\n", entrada.email);
            printf("Tipo: %s\n", entrada.admin ? "Admin" : "Cliente");
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhum usuário encontrado com o email: %s\n", emailFiltro);
    }

    fclose(arquivo);
}

void filtrar_usuario_por_tipo(const char *tipoFiltro) {
    FILE *arquivo = fopen(ARQUIVO_USUARIOS, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Usuario entrada;
    int encontrado = 0;
    bool tipoAdmin = (strcmp(tipoFiltro, "Admin") == 0);

    printf("Usuários (Filtrados por Tipo: %s):\n", tipoFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Usuario), 1, arquivo)) {
        if (entrada.admin == tipoAdmin) {
            encontrado = 1;
            printf("ID: %d\n", entrada.id);
            printf("Nome: %s\n", entrada.nome);
            printf("Email: %s\n", entrada.email);
            printf("Tipo: %s\n", entrada.admin ? "Admin" : "Cliente");
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhum usuário encontrado com o tipo: %s\n", tipoFiltro);
    }

    fclose(arquivo);
}
