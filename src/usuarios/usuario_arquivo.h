#ifndef USUARIO_ARQUIVO_H
#define USUARIO_ARQUIVO_H

#include <stdbool.h>

void salvar_usuario_arquivo(const Usuario *usuario);
void carregar_usuarios_arquivo(Usuario **usuarios, int *qtd_usuarios);
void atualizar_usuario_arquivo(int id);
void excluir_usuario_arquivo(int id);
int obter_proximo_id_usuario(void);
Usuario* buscar_usuario_arquivo(int id);

#endif 