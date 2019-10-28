STD = -std=c99
CFLAGS = -Wall -Wpedantic
CC = gcc $(STD) $(CFLAGS)

all: teste

teste: selection.o get.o printa.o vetor.h
	$(CC) -o "teste" teste.c selectionSort.o SelectionSort/selectionSort.h getVetor.o printaVetor.o vetor.h

printa.o: printaVetor.c
	$(CC) -c printaVetor.c

get.o: getVetor.c
	$(CC) -c getVetor.c

selection.o: SelectionSort/selectionSort.c compara.c compara.h troca.c vetor.h
	$(CC) -c SelectionSort/selectionSort.c compara.c compara.h troca.c vetor.h

troca.o: troca.c
	$(CC) -c troca.c

compara.o: compara.c compara.h
	$(CC) -c compara.c compara.h

clean:
	rm -f *.o* *.gch*