CC=gcc
CFLAGS=-std=c11 -Wpedantic -Wall -Wextra
LDLIBS=-lm
RM=rm -f

OBJ=main.o
EXE=main

# Pour exe main
main: main.c
	$(CC) $(CFLAGS) main.c -o main $(LDLIBS)
# Pour effacer les objets et les exécutables 
clean:
	$(RM) $(OBJ) $(EXE)