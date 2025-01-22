TARGET = programa

# Diretórios
SRC_DIR = src
RELATORIOS_DIR = $(SRC_DIR)/relatorios
TELAS_DIR = $(SRC_DIR)/telas
USUARIOS_DIR = $(SRC_DIR)/usuarios
VALIDACOES_DIR = $(SRC_DIR)/validacoes
PRODUTOS_DIR = $(SRC_DIR)/produtos

# Arquivos de código-fonte
MAIN = $(SRC_DIR)/main.c
SRC_FILES = $(RELATORIOS_DIR)/relatorios.c \
            $(TELAS_DIR)/telas.c \
            $(USUARIOS_DIR)/usuarios.c \
            $(USUARIOS_DIR)/ler_usuarios.c \
            $(USUARIOS_DIR)/usuario_arquivo.c \
            $(VALIDACOES_DIR)/validacoes.c \
            $(PRODUTOS_DIR)/produtos.c \
            $(PRODUTOS_DIR)/ler_produtos.c \
            $(PRODUTOS_DIR)/produto_arquivo.c

# Diretórios de cabeçalhos
INCLUDE_DIRS = -I $(RELATORIOS_DIR) \
               -I $(TELAS_DIR) \
               -I $(USUARIOS_DIR) \
               -I $(VALIDACOES_DIR) \
               -I $(PRODUTOS_DIR)

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic

# Regra principal para compilar o programa
$(TARGET): $(MAIN) $(SRC_FILES)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $(TARGET) $(MAIN) $(SRC_FILES)

# Regra para limpeza
clean:
	rm -f $(TARGET)
	rm -f *.o
