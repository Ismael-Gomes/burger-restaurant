#include <stdio.h>
#include <string.h>
#include "usuarios.h"

int validarUsuario(Usuario usuarios[], int totalUsuarios, char email[], char senha[]) {
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].email, email) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            return i; 
        }
    }
    return -1;
}

void cadastrarUsuario(Usuario usuarios[], int *totalUsuarios) {
    if (*totalUsuarios >= 10) {
        printf("Erro: Não há mais espaço para novos usuários.\n");
        return;
    }

    Usuario novoUsuario;
    novoUsuario.id = *totalUsuarios + 1;

    printf("Digite o nome do Usuário:\n");
    scanf(" %[^\n]%*c", novoUsuario.nome);

    printf("Digite o email do Usuário:\n");
    scanf("%s", novoUsuario.email);

    printf("Digite a senha do Usuário:\n");
    scanf("%s", novoUsuario.senha);

    novoUsuario.admin = false;

    usuarios[*totalUsuarios] = novoUsuario;
    (*totalUsuarios)++;

    printf("Usuário cadastrado com sucesso!\n");
}
