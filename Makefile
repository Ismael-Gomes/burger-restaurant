TARGET = programa

# Diretórios
SRC_DIR = src
TELAS_DIR = $(SRC_DIR)/telas
USUARIOS_DIR = $(SRC_DIR)/usuarios
VALIDACOES_DIR = $(SRC_DIR)/validacoes
RELATORIOS_DIR = $(SRC_DIR)/relatorios

# Arquivos de código-fonte
MAIN = $(SRC_DIR)/main.c
RC_FILES = $(RELATORIOS_DIR)/relatorios.c \
            $(TELAS_DIR)/telas.c \
            $(USUARIOS_DIR)/usuarios.c \
            $(VALIDACOES_DIR)/validacoes.c
# Diretórios de cabeçalhos
INCLUDE_DIRS = -I $(RELATORIOS_DIR) \
               -I $(TELAS_DIR) \
               -I $(USUARIOS_DIR) \
               -I $(VALIDACOES_DIR)

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic

# Regra principalpara compilar o programa
$(TARGET): $(MAIN) $(SRC_FILES)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $(TARGET) $(MAIN) $(SRC_FILES)

# Regra para limpeza
clean:
		rm -f $(TARGET)
		rm -f *.o