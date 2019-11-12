AUX = ../FunçõesAuxiliares/

STD = -std=c99
CFLAGS = -Wall -Wpedantic
INCLUDES = -I$(AUX) -I../
CC = gcc $(STD) $(CFLAGS) $(INCLUDES)

all: teste

teste: 	selectionSort.o insertionSort.o bubbleSort.o cocktailSort.o mergeSort.o quickSort.o heapSort.o \
		compara.o aleatorio.o confere.o manipula.o getVetor.o printaVetor.o teste.c ../vetor.h
	$(CC) -o "teste" teste.c *.o

printaVetor.o: $(AUX)printaVetor.c
	$(CC) -c $(AUX)printaVetor.c

getVetor.o: $(AUX)getVetor.c
	$(CC) -c $(AUX)getVetor.c

aleatorio.o: $(AUX)aleatorio.c
	$(CC) -c $(AUX)aleatorio.c

manipula.o: $(AUX)manipula.c
	$(CC) -c $(AUX)manipula.c

confere.o: $(AUX)confere.c
	$(CC) -c $(AUX)confere.c

compara.o: $(AUX)compara.c
	$(CC) -c $(AUX)compara.c
	
selectionSort.o: ../selectionSort.c
	$(CC) -c ../selectionSort.c

insertionSort.o: ../insertionSort.c
	$(CC) -c ../insertionSort.c

bubbleSort.o: ../bubbleSort.c
	$(CC) -c ../bubbleSort.c

cocktailSort.o: ../cocktailSort.c
	$(CC) -c ../cocktailSort.c

mergeSort.o: ../mergeSort.c
	$(CC) -c ../mergeSort.c

quickSort.o: ../quickSort.c
	$(CC) -c ../quickSort.c

heapSort.o: ../heapSort.c
	$(CC) -c ../heapSort.c

clean:
	rm -f *.o* *.gch*