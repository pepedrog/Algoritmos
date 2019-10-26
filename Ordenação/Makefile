STD = -std=c99
CFLAGS = -Wall -Wpedantic
CC = gcc $(STD) $(CFLAGS)

all: teste

teste: compara.o get.o printa.o vetor.h
	$(CC) -o "teste" teste.c compara.o getVetor.o printaVetor.o compara.h vetor.h

printa.o: printaVetor.c
	$(CC) -c printaVetor.c

get.o: getVetor.c
	$(CC) -c getVetor.c

compara.o: compara.c compara.h
	$(CC) -c compara.c compara.h

clean:
	rm -f *.o* *.gch*