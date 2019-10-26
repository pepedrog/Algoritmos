STD = -std=c99
CFLAGS = -Wall -Wpedantic

all: teste

teste: compara.o
	gcc -pedantic -o "teste" teste.c compara.o

compara.o: compara.c compara.h
	gcc $(STD) $(CFLAGS) -c compara.c compara.h

clean:
	rm -f *.o* *.gch*