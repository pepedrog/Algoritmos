AUX = ../FunçõesAuxiliares/

STD = -std=c99
CFLAGS = -Wall -Wpedantic
INCLUDES = -I$(AUX) -I../
CC = gcc $(STD) $(CFLAGS) $(INCLUDES)

all: teste

teste: 	selection.o insertion.o bubble.o cocktail.o merge.o \
		compara.o aleatorio.o confere.o manipula.o get.o printa.o ../vetor.h
	$(CC) -o "teste" teste.c *.o

printa.o: $(AUX)printaVetor.c
	$(CC) -c $(AUX)printaVetor.c

get.o: $(AUX)getVetor.c
	$(CC) -c $(AUX)getVetor.c

aleatorio.o: $(AUX)aleatorio.c
	$(CC) -c $(AUX)aleatorio.c

manipula.o: $(AUX)manipula.c
	$(CC) -c $(AUX)manipula.c

confere.o: $(AUX)confere.c
	$(CC) -c $(AUX)confere.c

compara.o: $(AUX)compara.c
	$(CC) -c $(AUX)compara.c
	
selection.o: ../selectionSort.c
	$(CC) -c ../selectionSort.c

insertion.o: ../insertionSort.c
	$(CC) -c ../insertionSort.c

bubble.o: ../bubbleSort.c
	$(CC) -c ../bubbleSort.c

cocktail.o: ../cocktailSort.c
	$(CC) -c ../cocktailSort.c

merge.o: ../mergeSort.c
	$(CC) -c ../mergeSort.c

clean:
	rm -f *.o* *.gch*