#ifndef USUARIO_H
#define USUARIO_H

#include <stdbool.h>

typedef struct {
    int id;
    char nome[100];
    char email[100];
    char senha[50];
    bool admin;
} Usuario;

int validarUsuario(Usuario usuarios[], int totalUsuarios, char email[], char senha[]);
void cadastrarUsuario(Usuario usuarios[], int *totalUsuarios);

#endif