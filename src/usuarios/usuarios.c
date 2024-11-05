#include <stdio.h>
#include <string.h>
#include "usuarios.h"
#include "validacoes.h"

void cadastrarUsuario(Usuario usuarios[], int *totalUsuarios) {
    if (*totalUsuarios >= 10) {
        printf("Erro: Não há mais espaço para novos usuários.\n");
        return;
    }

    Usuario novoUsuario;
    novoUsuario.id = *totalUsuarios + 1;

    printf("Digite o nome do Usuário:\n");
    scanf(" %[^\n]%*c", novoUsuario.nome);
    if (!validarNome(novoUsuario.nome)) return;

    printf("Digite o email do Usuário:\n");
    scanf("%s", novoUsuario.email);
    if (!validarEmail(novoUsuario.email)) return;

    printf("Digite a senha do Usuário:\n");
    scanf("%s", novoUsuario.senha);
    if (!validarSenha(novoUsuario.senha)) return;

    novoUsuario.admin = false;
    usuarios[*totalUsuarios] = novoUsuario;
    (*totalUsuarios)++;

    printf("Usuário cadastrado com sucesso!\n");
}
