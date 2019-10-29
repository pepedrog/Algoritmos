AUX = ../FunçõesAuxiliares/
SS = ../SelectionSort/
IS = ../InsertionSort/

STD = -std=c99
CFLAGS = -Wall -Wpedantic
INCLUDES = -I$(AUX) -I$(SS) -I$(IS) -I../
CC = gcc $(STD) $(CFLAGS) $(INCLUDES)

all: teste

teste: selection.o insertion.o compara.o manipula.o get.o printa.o ../vetor.h
	$(CC) -o "teste" teste.c selectionSort.o insertionSort.o compara.o manipula.o getVetor.o printaVetor.o

printa.o: $(AUX)printaVetor.c
	$(CC) -c $(AUX)printaVetor.c

get.o: $(AUX)getVetor.c
	$(CC) -c $(AUX)getVetor.c

selection.o: $(SS)/selectionSort.c $(AUX)compara.h ../vetor.h
	$(CC) -c $(SS)selectionSort.c

insertion.o: $(IS)/insertionSort.c $(AUX)compara.h ../vetor.h
	$(CC) -c $(IS)insertionSort.c

manipula.o: $(AUX)manipula.c
	$(CC) -c $(AUX)manipula.c

compara.o: $(AUX)compara.c $(AUX)compara.h
	$(CC) -c $(AUX)compara.c

clean:
	rm -f *.o* *.gch*