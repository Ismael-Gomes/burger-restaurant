#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "../validacoes/validacoes.h"
#include "usuarios.h"

void ler_id_usuario(int *id) {
    do {
        printf("Digite o ID do usuário (número inteiro positivo): ");
        if (scanf("%d", id) != 1 || *id <= 0) {
            printf("ID inválido! Por favor, insira um número inteiro positivo.\n");
            while (getchar() != '\n'); 
        } else {
            break;
        }
    } while (1);
    getchar(); 
}

void ler_nome_usuario(char *nome, size_t tamanho) {
    do {
        printf("Digite o nome do usuário: ");
        fgets(nome, tamanho, stdin);
        limparEspacos(nome); 
        if (!validarNome(nome)) {
            printf("Nome inválido! O nome deve ter pelo menos 3 caracteres.\n");
        }
    } while (!validarNome(nome));
}

void ler_email_usuario(char *email, size_t tamanho) {
    do {
        printf("Digite o email do usuário: ");
        fgets(email, tamanho, stdin);
        limparEspacos(email); 
        if (!validarEmail(email)) {
            printf("Email inválido! Certifique-se de inserir um email no formato correto.\n");
        }
    } while (!validarEmail(email));
}

void ler_senha_usuario(char *senha, size_t tamanho) {
    do {
        printf("Digite a senha do usuário: ");
        fgets(senha, tamanho, stdin);
        limparEspacos(senha); 
        if (!validarSenha(senha)) {
            printf("Senha inválida! A senha deve conter pelo menos:\n");
            printf("- 6 caracteres\n- 1 número\n- 1 letra maiúscula\n- 1 letra minúscula\n- 1 símbolo especial\n");
        }
    } while (!validarSenha(senha));
}

void ler_status_admin_usuario(bool *admin) {
    char escolha;
    do {
        printf("O usuário é administrador? (s/n): ");
        scanf(" %c", &escolha);
        escolha = tolower(escolha);
        if (escolha == 's') {
            *admin = true;
            break;
        } else if (escolha == 'n') {
            *admin = false;
            break;
        } else {
            printf("Opção inválida! Por favor, digite 's' para sim ou 'n' para não.\n");
        }
    } while (1);
    getchar();
}
