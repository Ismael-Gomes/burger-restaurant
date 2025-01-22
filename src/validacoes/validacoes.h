#ifndef VALIDACOES_H
#define VALIDACOES_H

#include "../usuarios/usuarios.h"

// Validação para autenticar um usuário pelo email e senha
int validarUsuario(Usuario usuarios[], int totalUsuarios, char email[], char senha[]);

// Validação para o nome do usuário
int validarNome(char nome[]);

// Validação para o email do usuário
int validarEmail(char email[]);

// Validação para a senha do usuário
int validarSenha(char senha[]);

void limparEspacos(char *str);

void remove_newline(char *str);

#endif