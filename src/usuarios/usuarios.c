#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include "usuarios.h"
#include "ler_usuario.h"
#include "usuario_arquivo.h"

void menu_usuario() {
    int escolha;
    do {
        system("clear||cls");
        printf("\n");
        printf("/////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = = = = = Menu Usuários = = = = = = = = =           ///\n");
        printf("///                                                                       ///\n");
        printf("///            1. Cadastrar um Usuário                                    ///\n");
        printf("///            2. Pesquisar Usuários                                      ///\n");
        printf("///            3. Atualizar Usuário                                       ///\n");
        printf("///            4. Excluir um Usuário                                      ///\n");
        printf("///            0. Voltar ao menu anterior                                 ///\n");
        printf("///                                                                       ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &escolha);
        getchar();

        switch (escolha) {
            case 1:
                cadastrar_usuario();
                break;
            case 2:
                pesquisar_usuario();
                break;
            case 3:
                atualizar_usuario();
                break;
            case 4:
                excluir_usuario();
                break;
            case 0:
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;
        }
    } while (escolha != 0);
}

void cadastrar_usuario(void) {
    Usuario usuario;
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Novo Usuário = = = = = = = = = =          ///\n");
    printf("///                                                                           ///\n");
    printf("/// Informe os dados do usuário:                                              ///\n");

    ler_nome_usuario(usuario.nome, sizeof(usuario.nome));
    ler_email_usuario(usuario.email, sizeof(usuario.email));
    ler_senha_usuario(usuario.senha, sizeof(usuario.senha));

    // Corrigido o uso do _Bool
    int admin_input;
    printf("O usuário será administrador? (1 - Sim, 0 - Não): ");
    scanf("%d", &admin_input);
    getchar();
    usuario.admin = (admin_input != 0); // Converte para _Bool

    usuario.id = obter_proximo_id_usuario();
    salvar_usuario_arquivo(&usuario);

    printf("/////////////////////////////////////////////////////////////////////////////////\n");
    printf("///            Usuário cadastrado com sucesso!                                ///\n");
    printf("///            ID: %d\n", usuario.id);
    printf("///            Nome: %s\n", usuario.nome);
    printf("///            Email: %s\n", usuario.email);
    printf("///            Administrador: %s\n", usuario.admin ? "Sim" : "Não");
    printf("/////////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void pesquisar_usuario(void) {
    int id;
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Usuário = = = = = = = = = = = =            ///\n");
    printf("///                                                                           ///\n");
    printf("/// Informe o ID do usuário para pesquisa: ");
    ler_id_usuario(&id);

    Usuario *usuario = buscar_usuario_arquivo(id);

    if (usuario != NULL) {
        printf("/////////////////////////////////////////////////////////////////////////////\n");
        printf("///            Usuário encontrado:                                        ///\n");
        printf("///            ID: %d\n", usuario->id);
        printf("///            Nome: %s\n", usuario->nome);
        printf("///            Email: %s\n", usuario->email);
        printf("///            Administrador: %s\n", usuario->admin ? "Sim" : "Não");
        printf("/////////////////////////////////////////////////////////////////////////////\n");
        free(usuario);
    } else {
        printf("/////////////////////////////////////////////////////////////////////////////\n");
        printf("///            Usuário não encontrado!                                    ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////\n");
    }
    printf("/////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualizar_usuario(void) {
    int id;
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///              = = = = = Atualizar Usuário = = = = = = = = = = = =          ///\n");
    printf("///                                                                           ///\n");
    printf("/// Informe o ID do usuário que deseja atualizar: ");
    ler_id_usuario(&id);
    atualizar_usuario_arquivo(id);
    printf("/////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void excluir_usuario(void) {
    int id;
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///              = = = = = Excluir Usuário = = = = = = = = = = = =            ///\n");
    printf("///                                                                           ///\n");
    printf("/// Informe o ID do usuário que deseja excluir: ");
    ler_id_usuario(&id);
    excluir_usuario_arquivo(id);
    printf("/////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
