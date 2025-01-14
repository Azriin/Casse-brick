# Variables
CC = gcc
CFLAGS = -std=c11 -Wpedantic -Wall -Wextra
LDLIBS = -lm
RM = rm -f

SRC = main.c brick.c balle.c chainLink.c reflect.c
OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)  # Fichiers de dépendances générés automatiquement
EXE = main

# Règles
all: $(EXE)

# Compilation de l'exécutable
$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

# Compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Génération des dépendances
%.d: %.c
	$(CC) -MM $< -MF $@

# Inclusion des fichiers de dépendances
-include $(DEPS)

# Nettoyage
clean:
	$(RM) $(OBJ) $(EXE) $(DEPS)

# Indique que "clean" n'est pas un fichier
.PHONY: all clean
