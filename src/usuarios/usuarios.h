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

int validarUsuario(Usuario usuarios[], int totalUsuarios, char email[], char senha[]);
void cadastrarUsuario(Usuario usuarios[], int *totalUsuarios);
void salvarUsuarios(Usuario usuarios[], int totalUsuarios);
int carregarUsuarios(Usuario usuarios[]);

#endif
