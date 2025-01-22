#ifndef RELATORIO_USUARIOS_H
#define RELATORIO_USUARIOS_H
#define ARQUIVO_USUARIOS "usuarios.dat"

void inicializarArquivoUsuarios();
void listarRelatoriosUsuarios();
void menu_relatorio_usuario(void);
void filtrar_usuario_por_nome(const char *nomeFiltro);
void filtrar_usuario_por_email(const char *emailFiltro);
void filtrar_usuario_por_tipo(const char *tipoFiltro);

#endif 
