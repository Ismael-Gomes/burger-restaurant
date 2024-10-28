#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "./telas/telas.h"

typedef struct Usuario {
    int id;
    char nome[50];
    char email[50];
    char senha[50];
    bool admin;
} Usuario;

int validarUsuario(Usuario usuarios[], int totalUsuarios, char email[], char senha[]) {
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].email, email) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            return i; 
        }
    }
    return -1;
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

    printf("Digite o email do Usuário:\n");
    scanf("%s", novoUsuario.email);

    printf("Digite a senha do Usuário:\n");
    scanf("%s", novoUsuario.senha);

    novoUsuario.admin = false;

    usuarios[*totalUsuarios] = novoUsuario;
    (*totalUsuarios)++;

    printf("Usuário cadastrado com sucesso!\n");
}

int main(void) {
    bool resposta = true;
    int opcao, contador;
    char email[50], senha[50];


    Usuario usuarios[10] = {
        {1, "Ismael", "ismael@admin.com", "123456", true},
        {2, "Kaique", "kaique@admin.com", "senha123", true},
        {3, "Mopa", "mopa@admin.com", "abc123", false}
    };
    int totalUsuarios = 3;

    while (resposta) {
        telaLogin();
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Obrigado, até a próxima!\n");
                resposta = false;
                break;

            case 1:
                printf("Digite o email do Usuário:\n");
                scanf("%s", email);

                printf("Digite a senha do Usuário:\n");
                scanf("%s", senha);

                int usuarioIndex = validarUsuario(usuarios, totalUsuarios, email, senha);

                if (usuarioIndex != -1) {
                    if (usuarios[usuarioIndex].admin) {
                        printf("Login bem-sucedido! Bem-vindo, Admin %s.\n", usuarios[usuarioIndex].nome);
                        bool respostaMenuAdmin = true;
                        while (respostaMenuAdmin) {
                            menuAdmin(); 
                            scanf("%d", &opcao);
                            switch (opcao) {
                            case 1:
                                telaGerenciaProduto();
                                scanf("%d", &opcao);
                                switch (opcao) {
                                case 1:
                                    telaGerenciaHamburguer();
                                    scanf("%d", &opcao);
                                    break;
                                case 2:
                                    telaGerenciaProduto();
                                    break;
                                default:
                                    break;
                                }
                                break;
                            case 2:
                                telaGerenciaFuncionario();
                                scanf("%d", &opcao);
                                break;
                            case 3:
                                telaGerenciaPedido();
                                scanf("%d", &opcao);
                                break;

                            case 4:
                                telaRelatorio();
                                scanf("%d", &opcao);
                                break;
                            case 0:
                                respostaMenuAdmin = false;
                                break;
                            default:
                                printf("Valor inválido. Tente novamente.\n");
                                break;
                            }
                        }
                    } else {
                        printf("Login bem-sucedido! Bem-vindo, Cliente %s.\n", usuarios[usuarioIndex].nome);
                        bool resposta_menu_cliente = true;
                        while (resposta_menu_cliente){
                            menuCliente(); // Redireciona para o menu de cliente
                            scanf("%d", &opcao);
                            switch (opcao){
                                case 1:
                                    telaMenuCardapio();
                                    scanf("%d", &opcao);
                                    bool resposta_menu_cardapio = true;
                                    while (resposta_menu_cardapio){
                                        switch (opcao){
                                            case 1:
                                            //Artesanal
                                                break;
                                            case 2:
                                            //Lanche
                                                break;
                                            case 3:
                                            //Acompanhamento
                                                break;
                                            case 4:
                                            //Bebida
                                                break;
                                            case 0:
                                            resposta_menu_cardapio = false;
                                                break;
                                            default:
                                                break;
                                        }
                                    }
                                    break;
                                case 2:
                                    telaMenuCompra();
                                    scanf("%d", &opcao);
                                    bool resposta_menu_compra = true;
                                    while (resposta_menu_compra){
                                        switch (opcao){
                                            case 1:
                                            //Escolher Pedido
                                                break;
                                            case 2:
                                            //Carrinho
                                                break;
                                            case 3:
                                            //Pagamento
                                                break;
                                            case 0:
                                            resposta_menu_compra = false;
                                                break;
                                            default:
                                                break;
                                        }
                                    }
                                    break;
                                case 3:
                                    telaStatusCompra();
                                    scanf("%d", &opcao);
                                    bool resposta_status_compra = true;
                                    while (resposta_status_compra){
                                        switch (opcao){
                                            case 1:
                                            //Verificar Status
                                                break;
                                            case 0:
                                            resposta_status_compra = false;
                                                break;
                                            default:
                                                break;
                                        }
                                    }
                                    break;
                                case 4:
                                    telaPerfilCliente();
                                    scanf("%d", &opcao);
                                    bool resposta_perfil_cliente = true;
                                    while (resposta_perfil_cliente){
                                        switch (opcao){
                                            case 1:
                                            //Ver Dados
                                                break;
                                            case 2:
                                            //Alterar Dados
                                                break;
                                            case 3:
                                            //Cadastrar Endereço
                                                break;
                                            case 4:
                                            //Apagar Conta
                                                break;
                                            case 0:
                                            resposta_perfil_cliente = false;
                                                break;
                                            default:
                                                break;
                                        }
                                    }
                                    break;
                                case 0:
                                    resposta_menu_cliente = false;
                                    break;
                                default:
                                    break;
                            }
                        }
                        //estrutura do codigo todo
                    }
                } else {
                    printf("Email ou senha incorretos. Tente novamente.\n");
                }
                break;
            case 2:
                cadastrarUsuario(usuarios, &contador);
                break;

            default:
                printf("Valor inválido. Tente novamente.\n");
                break;
        }
    }

    return 0;
}