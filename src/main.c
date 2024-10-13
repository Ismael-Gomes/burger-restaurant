#include <stdio.h>
#include<stdbool.h>

void telaLogin(void){
    printf("=========================================\n");
    printf("|               BEM VINDO!              |\n");
    printf("=========================================\n");
    printf("|---------------------------------------|\n");
    printf("|                  LOGIN                |\n");
    printf("|---------------------------------------|\n");
    printf("#### 1 - Login                          |\n");
    printf("#### 2 - Não Possuo Cadastro            |\n");
    printf("#### 0 - Sair                           |\n");
    printf("----------------------------------------|\n");
    printf("#### Selecione uma das opcoes: \n");
}

void menuAdmin(void){
    printf("\n=========================================\n");
    printf("|           BURGUER RESTAURANT          |\n");
    printf("=========================================\n");
    printf("|---------------------------------------|\n");
    printf("|    Bem-vindo a Burguer Restaurant!    |\n");
    printf("|---------------------------------------|\n");
    printf("#### 1 - Gerenciamento de Produtos      |\n");
    printf("#### 2 - Gerenciamento de Funcionários  |\n");
    printf("#### 3 - Pedidos                        |\n");
    printf("#### 4 - Relatório                      |\n");
    printf("#### 0 - Sair                           |\n");
    printf("----------------------------------------|\n");
    printf("#### Selecione uma das opcoes: \n");
}

void telaGerenciaProduto(void){
    printf("\n========================================|\n");
    printf("|           BURGUER RESTAURANT          |\n");
    printf("=========================================\n");
    printf("|---------------------------------------|\n");
    printf("|           GERENCIAR PRODUTOS          |\n");
    printf("|---------------------------------------|\n");
    printf("#### 1 - Gerenciamento de Hamburgueres  |\n");
    printf("#### 2 - Gerenciamento de Bebidas       |\n");
    printf("#### 0 - Sair                           |\n");
    printf("----------------------------------------|\n");
    printf("#### Selecione uma das opcoes: \n");
}

void telaGerenciaHamburguer(void){
    printf("\n========================================|\n");
    printf("|           BURGUER RESTAURANT          |\n");
    printf("=========================================\n");
    printf("|---------------------------------------|\n");
    printf("|         GERENCIAR HAMBURGUERES        |\n");
    printf("|---------------------------------------|\n");
    printf("#### 1 - Cadastrar Hambugueres          |\n");
    printf("#### 2 - Atualizar Hambuguer            |\n");
    printf("#### 3 - Editar Hambuguer               |\n");
    printf("#### 4 - Excluir Hambuguer              |\n");
    printf("#### 0 - Sair                           |\n");
    printf("----------------------------------------|\n");
    printf("#### Selecione uma das opcoes: \n");
}

void telaGerenciaBebida(void){
    printf("\n========================================|\n");
    printf("|           BURGUER RESTAURANT          |\n");
    printf("========================================|\n");
    printf("|---------------------------------------|\n");
    printf("|           GERENCIAR BEBIDAS           |\n");
    printf("|---------------------------------------|\n");
    printf("#### 1 - Cadastrar Bebidas              |\n");
    printf("#### 2 - Atualizar Bebida               |\n");
    printf("#### 3 - Editar Bebida                  |\n");
    printf("#### 4 - Excluir Bebida                 |\n");
    printf("#### 0 - Sair                           |\n");
    printf("----------------------------------------|\n");
    printf("#### Selecione uma das opcoes: \n");
}

void telaGerenciaFuncionario(void){
    printf("\n========================================|\n");
    printf("|           BURGUER RESTAURANT          |\n");
    printf("========================================|\n");
    printf("|---------------------------------------|\n");
    printf("|           GERENCIAR FUNCIONARIOS      |\n");
    printf("|---------------------------------------|\n");
    printf("#### 1 - Cadastrar Funcionarios         |\n");
    printf("#### 2 - Atualizar Funcionario          |\n");
    printf("#### 3 - Editar Funcionario             |\n");
    printf("#### 4 - Excluir Funcionario            |\n");
    printf("#### 0 - Sair                           |\n");
    printf("----------------------------------------|\n");
    printf("#### Selecione uma das opcoes: \n");
}

void telaGerenciaPedido(void){
    printf("\n========================================|\n");
    printf("|           BURGUER RESTAURANT          |\n");
    printf("========================================|\n");
    printf("|---------------------------------------|\n");
    printf("|               PEDIDOS                 |\n");
    printf("|---------------------------------------|\n");
    printf("#### 1 - Lista de Pedidos               |\n");
    printf("#### 2 - Pedidos Finalizados            |\n");
    printf("#### 0 - Sair                           |\n");
    printf("----------------------------------------|\n");
    printf("#### Selecione uma das opcoes: \n");
}

void telaRelatorio(void){
    printf("\n========================================|\n");
    printf("|           BURGUER RESTAURANT          |\n");
    printf("========================================|\n");
    printf("|---------------------------------------|\n");
    printf("|               RELATÓRIOS              |\n");
    printf("|---------------------------------------|\n");
    printf("#### 1 - Pedidos do Dia                 |\n");
    printf("#### 2 - Quantidades de Pedidos do Dia  |\n");
    printf("#### 3 - Quantidades de Pedidos Por Mês |\n");
    printf("#### 0 - Sair                           |\n");
    printf("----------------------------------------|\n");
    printf("#### Selecione uma das opcoes: \n");
}

void menuCliente(void){
    printf("\n=========================================\n");
    printf("|           BURGUER RESTAURANT          |\n");
    printf("=========================================\n");
    printf("|---------------------------------------|\n");
    printf("|    Bem-vindo a Burguer Restaurant!    |\n");
    printf("|---------------------------------------|\n");
    printf("#### 1 - Cardápio                       |\n");
    printf("#### 2 - Realizar Compra                |\n");
    printf("#### 3 - Status da Compra               |\n");
    printf("#### 4 - Meu Perfil                     |\n");
    printf("#### 0 - Sair                           |\n");
    printf("----------------------------------------|\n");
    printf("#### Selecione uma das opcoes: \n");
}

void telaMenuCardapio(void){
    printf("\n=========================================\n");
    printf("|           BURGUER RESTAURANT          |\n");
    printf("=========================================\n");
    printf("|---------------------------------------|\n");
    printf("|                Cardápio               |\n");
    printf("|---------------------------------------|\n");
    printf("#### 1 - Artesanais                     |\n");
    printf("#### 2 - Lanches                        |\n");
    printf("#### 3 - Acompanhamentos                |\n");
    printf("#### 4 - Bebidas                        |\n");
    printf("#### 0 - Sair                           |\n");
    printf("----------------------------------------|\n");
    printf("#### Selecione uma das opcoes: \n");
}

void telaMenuCompra(void){
    printf("\n=========================================\n");
    printf("|           BURGUER RESTAURANT          |\n");
    printf("=========================================\n");
    printf("|---------------------------------------|\n");
    printf("|                 Comprar               |\n");
    printf("|---------------------------------------|\n");
    printf("#### 1 - Escolher pedido                |\n");
    printf("#### 2 - Carrinho                       |\n");
    printf("#### 3 - Pagamento                      |\n");
    printf("#### 0 - Sair                           |\n");
    printf("----------------------------------------|\n");
    printf("#### Selecione uma das opcoes: \n");
}

void telaStatusCompra(void){
    printf("\n=========================================\n");
    printf("|           BURGUER RESTAURANT          |\n");
    printf("=========================================\n");
    printf("|---------------------------------------|\n");
    printf("|                 Status                |\n");
    printf("|---------------------------------------|\n");
    printf("#### 1 - Verificar Status               |\n");
    printf("#### 0 - Sair                           |\n");
    printf("----------------------------------------|\n");
    printf("#### Selecione uma das opcoes: \n");
}

void telaPerfilCliente(void){
    printf("\n=========================================\n");
    printf("|           BURGUER RESTAURANT          |\n");
    printf("=========================================\n");
    printf("|---------------------------------------|\n");
    printf("|                Meu Perfil             |\n");
    printf("|---------------------------------------|\n");
    printf("#### 1 - Ver Dados                      |\n");
    printf("#### 2 - Alterar Dados                  |\n");
    printf("#### 3 - Cadastrar Endereço             |\n");
    printf("#### 4 - Apagar Conta                   |\n");
    printf("#### 5 - Sair                           |\n");
    printf("----------------------------------------|\n");
    printf("#### Selecione uma das opcoes: \n");
}

int main(void) {

    bool resposta = true;
    int opcao;
    char email, senha;

    while (resposta) {
        telaLogin();
        scanf(" %d", &opcao);


        switch (opcao) {
        case 0:
            printf("Obrigado, até a proxima!!\n");
            resposta = false;
            break;
        
        case 1:
            printf("Digite o email do Usuário:\n");
            scanf(" %c", &email);

            printf("Digite a senha do Usuário:\n");
            scanf(" %c", &senha);

            //função de validação de usuario
            break;

        case 2:
            //função de cadastro de usuario

            break;
        
        default:
            printf("Valor invalido:");
            break;
        }    
    }
}

typedef struct Usuario {
    int id;
    char nome[50];
    char* email[50];
    char* senha[50];
    bool cliente;
    struct Usuario* proximo;
} Usuario;