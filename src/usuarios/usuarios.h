#ifndef USUARIOS_H
#define USUARIOS_H

#include <stdbool.h>

typedef struct {
    int id;
    char nome[100];
    char email[50];
    char senha[50];
    bool admin;
} Usuario;

void menu_usuario(void);

void cadastrar_usuario(void);

void pesquisar_usuario(void);

void atualizar_usuario(void);

void excluir_usuario(void);

#endif