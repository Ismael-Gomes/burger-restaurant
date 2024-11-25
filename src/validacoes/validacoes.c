#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "usuarios.h"
#include "validacoes.h"

int validarUsuario(Usuario usuarios[], int totalUsuarios, char email[], char senha[]) {
    // Limpar espaços 
    limparEspacos(email);
    limparEspacos(senha);

    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].email, email) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            return 1;  // Usuário encontrado
        }
    }
    return 0;  // Usuário não encontrado
}


int validarNome(char nome[]) {
    if (strlen(nome) < 3) {
        printf("Erro: O nome deve ter pelo menos 3 caracteres.\n");
        return 0;
    }
    limparEspacos(nome);  // Limpar espaços 
    return 1;
}

int validarEmail(char email[]) {
    if (strstr(email, "@") == NULL || strstr(email, ".") == NULL) {
        printf("Erro: O email deve conter '@' e um domínio válido.\n");
        return 0;
    }
    return 1;
}

int validarSenha(char senha[]) {
    if (strlen(senha) < 6) {
        printf("Erro: A senha deve ter pelo menos 6 caracteres.\n");
        return 0;
    }

    int temNumero = 0, temMaiuscula = 0, temMinuscula = 0, temEspecial = 0;
    
    for (int i = 0; i < strlen(senha); i++) {
        if (isdigit(senha[i])) temNumero = 1;
        if (isupper(senha[i])) temMaiuscula = 1;
        if (islower(senha[i])) temMinuscula = 1;
        if (ispunct(senha[i])) temEspecial = 1;
    }

    if (!temNumero || !temMaiuscula || !temMinuscula || !temEspecial) {
        printf("Erro: A senha deve conter pelo menos um número, uma letra maiúscula, uma letra minúscula e um símbolo.\n");
        return 0;
    }

    return 1;
}
// Função para limpar espaços no início e no fim da string
void limparEspacos(char *str) {
    char *inicio = str;
    char *fim = str + strlen(str) - 1;

    // Remover espaços da esquerda
    while (isspace(*inicio)) {
        inicio++;
    }

    // Remover espaços da direita
    while (fim > inicio && isspace(*fim)) {
        fim--;
    }

    *(fim + 1) = '\0';

    // Mover a string para a esquerda (caso haja espaços à esquerda)
    if (inicio != str) {
        memmove(str, inicio, strlen(inicio) + 1);
    }
}

