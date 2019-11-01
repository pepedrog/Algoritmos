AUX = ../FunçõesAuxiliares/

STD = -std=c99
CFLAGS = -Wall -Wpedantic
INCLUDES = -I$(AUX) -I../
CC = gcc $(STD) $(CFLAGS) $(INCLUDES)

all: teste

teste: selection.o insertion.o bubble.o aleatorio.o compara.o manipula.o get.o printa.o ../vetor.h
	$(CC) -o "teste" teste.c *.o

printa.o: $(AUX)printaVetor.c
	$(CC) -c $(AUX)printaVetor.c

get.o: $(AUX)getVetor.c
	$(CC) -c $(AUX)getVetor.c

selection.o: ../selectionSort.c $(AUX)compara.h ../vetor.h
	$(CC) -c ../selectionSort.c

insertion.o: ../insertionSort.c $(AUX)compara.h ../vetor.h
	$(CC) -c ../insertionSort.c

bubble.o: ../bubbleSort.c $(AUX)compara.h ../vetor.h
	$(CC) -c ../bubbleSort.c

aleatorio.o: $(AUX)aleatorio.c
	$(CC) -c $(AUX)aleatorio.c

manipula.o: $(AUX)manipula.c
	$(CC) -c $(AUX)manipula.c

compara.o: $(AUX)compara.c $(AUX)compara.h
	$(CC) -c $(AUX)compara.c

clean:
	rm -f *.o* *.gch*