# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -Iinclude -MMD -MP

# Nom de l'exécutable
TARGET = crashTech.exe

# Dossiers
SRC_DIR = src
OBJ_DIR = obj

# Recherche les .c dans src/ et ses sous-dossiers (jusqu'à 2 niveaux)
SRC = $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c $(SRC_DIR)/*/*/*.c)

# Génération des fichiers objets (.o) et dépendances (.d)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
DEP = $(OBJ:.o=.d)

# Règle principale
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compilation des fichiers .c en .o + création automatique des sous-dossiers dans obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	$(CC) $(CFLAGS) -c $< -o $@

# Inclusion des dépendances des .h
-include $(DEP)

# Nettoyage des fichiers générés
clean:
	-if exist $(OBJ_DIR) rmdir /S /Q $(OBJ_DIR)
	-del /Q $(TARGET) 2>NUL

# Recompilation complète
rebuild: clean all

.PHONY: all clean rebuild
