#ifndef LER_USUARIOS_H
#define LER_USUARIOS_H

#include <stdbool.h>
#include <stddef.h>
#include "usuarios.h"

void ler_id_usuario(int *id);
void ler_nome_usuario(char *nome, size_t tamanho);
void ler_email_usuario(char *email, size_t tamanho);
void ler_senha_usuario(char *senha, size_t tamanho);
void ler_status_admin_usuario(bool *admin);

#endif