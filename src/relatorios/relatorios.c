#include "relatorio.h"
#include <stdio.h>


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
void relatorioProdutos() {
    printf("\\n=== Relatório de Produtos ===\\n");
    // Implementar lógica para listar produtos
}

void relatorioFuncionarios() {
    printf("\\n=== Relatório de Funcionários ===\\n");
    // Implementar lógica para listar funcionários
}

void relatorioPedidos() {
    printf("\\n=== Relatório de Pedidos ===\\n");
    // Implementar lógica para listar pedidos
}

