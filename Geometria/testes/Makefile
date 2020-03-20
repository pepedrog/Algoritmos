AUX = ../../Ordenação/FunçõesAuxiliares

CFLAGS = -std=c99 -Wall -O3 
CC = gcc $(CFLAGS) -I$(AUX) -I../

pontosProximos: pontosProximos.o ponto.o mergeSort.o manipula.o teste_pontosProximos.c
	$(CC) -o teste_pontosProximos teste_pontosProximos.c \
	pontosProximos.o ponto.o mergeSort.o manipula.o

triangulacao: poligono.o ponto.o teste_triangulacao.c
	$(CC) -o teste_triangulacao teste_triangulacao.c \
	ponto.o poligono.o 

pontosProximos.o: ../pontosProximos.c
	$(CC) -c ../pontosProximos.c

poligono.o: ../poligono.c 
	$(CC) -c ../poligono.c

ponto.o: ../ponto.c
	$(CC) -c ../ponto.c

mergeSort.o: ../../Ordenação/mergeSort.c 
	$(CC) -c ../../Ordenação/mergeSort.c

manipula.o: ../../Ordenação/FunçõesAuxiliares/manipula.c
	$(CC) -c ../../Ordenação/FunçõesAuxiliares/manipula.c