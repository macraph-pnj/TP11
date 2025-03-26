CC=gcc
CFLAGS=-std=c99 -Wall -g
LDFLAGS=-lm -lMLV
DEPS=affichage.h taquin.h
OBJ=affichage.o taquin.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) main
