#include "relatorio.h"
#include <stdio.h>

void telaRelatorio() {
    printf("\\n\\n");
    printf("///           = = = = = = = = = Relatórios = = = = = = = = =             ///\\n");
    printf("///                                                                       ///\\n");
    printf("///           1. Relatório de Produtos                                    ///\\n");
    printf("///           2. Relatório de Funcionários                                ///\\n");
    printf("///           3. Relatório de Pedidos                                     ///\\n");
    printf("///           0. Voltar                                                   ///\\n");
    printf("///                                                                       ///\\n");
    printf("///           Escolha a opção desejada:                                   ///\\n");
    printf("\\n\\n");
}
 void gerarRelatorio(int opcao) {
    switch (opcao) {
        case 1:
        relatorioProdutos();
            break;
        case 2:
            relatorioFuncionarios();
            break;
        case 3:
            relatorioPedidos();
            break;
        case 0:
            printf("Voltando ao menu anterior...\\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\\n");
            break;
    }
}
