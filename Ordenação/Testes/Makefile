STD = -std=c99
CFLAGS = -Wall -Wpedantic
INCLUDES = -I../FunçõesAuxiliares/ -I../SelectionSort/ -I../
CC = gcc $(STD) $(CFLAGS) $(INCLUDES)

AUX = ../FunçõesAuxiliares/
SS = ../SelectionSort/

all: teste

teste: selection.o compara.o troca.o get.o printa.o ../vetor.h
	$(CC) -o "teste" teste.c selectionSort.o compara.o troca.o getVetor.o printaVetor.o

printa.o: $(AUX)printaVetor.c
	$(CC) -c $(AUX)printaVetor.c

get.o: $(AUX)getVetor.c
	$(CC) -c $(AUX)getVetor.c

selection.o: $(SS)/selectionSort.c $(AUX)compara.h ../vetor.h
	$(CC) -c $(SS)selectionSort.c

troca.o: $(AUX)troca.c
	$(CC) -c $(AUX)troca.c

compara.o: $(AUX)compara.c $(AUX)compara.h
	$(CC) -c $(AUX)compara.c

clean:
	rm -f *.o* *.gch*