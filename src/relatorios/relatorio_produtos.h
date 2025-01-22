#ifndef RELATORIO_PRODUTOS_H
#define RELATORIO_PRODUTOS_H

#define ARQUIVO_PRODUTOS "produtos.dat"

void inicializarArquivoProdutos();
double listarRelatoriosProdutos();
void menu_relatorio_produto(void);
void filtrar_produto_por_nome(const char *nomeFiltro);
void filtrar_produto_por_valor(const char *valorFiltro);
void filtrar_produto_por_quantidade(const char *quantidadeFiltro);

#endif 