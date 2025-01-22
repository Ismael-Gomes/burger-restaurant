#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"
#include "relatorio_usuarios.h"
#include "relatorio_produtos.h"

void menu_relatorios(void) {
    int escolha;
    do {
        system("clear||cls");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = = = = = Menu Relatórios = = = = = = = = =          ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Relatórios de Produtos                                    ///\n");
        printf("///            2. Relatórios de Usuários                                     ///\n");
        printf("///            0. Retornar ao menu principal                                ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &escolha);
        getchar();
        switch (escolha) {
            case 1:
                relatorios_produto();
                break;
            case 2:
                relatorios_usuario();
                break;
            case 0:
                break;
            default:
                printf("\t\t\t>Opção inválida! Tente novamente.\n");
                printf("///                                                                         ///\n");
                printf("///////////////////////////////////////////////////////////////////////////////\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;
        }
    } while (escolha != 0);
}

void relatorios_produto(void) {
    system("clear||cls");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Relatório de Produtos = = = =                      ///\n");
    menu_relatorio_produto();
    printf("/////////////////////////////////////////////////////////////////////////////////\n");
}

void relatorios_usuario(void) {
    system("clear||cls");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Relatório de Usuários = = = =                       ///\n");
    menu_relatorio_usuario();
    printf("/////////////////////////////////////////////////////////////////////////////////\n");
}
