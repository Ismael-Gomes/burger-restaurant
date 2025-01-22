#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../usuarios/usuarios.h"
#include "./relatorios/relatorios.h"
#include "./produtos/produtos.h"

char exibir_menu(void);
void tela_sobre(void);
void tela_equipe(void);

int main(void) {
    char escolha;

    do {
        escolha = exibir_menu();
        switch(escolha) {
            case '1':   menu_usuario();
                        break;
            case '2':   menu_produto();
                        break;
            case '3':   menu_relatorios();
                        break;
        } 	
    } while (escolha != '0');

    return 0;
}


char exibir_menu(void) {
    char escolha;



         system("clear||cls");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///   Escolha um módulo:                                                    ///\n");
        printf("///   1. Usuario                                                            ///\n");
        printf("///   2. Produtos                                                           ///\n");
        printf("///   3. Relatorios                                                         ///\n");
        printf("///   4. Equipe                                                             ///\n");
        printf("///   0. Sair                                                               ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("#### Selecione uma das opções: \n");
        scanf("%c", &escolha);    
        getchar();
        printf("///                                                                         ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("\t\t\t<<< ... Aguarde ... >>>\n");
        sleep(1);
        return escolha;
}


