#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "../vetor.h"
#include "../SelectionSort/selectionSort.h"
#include "../InsertionSort/insertionSort.h"

int main (void) {
    int n;
    if (!scanf ("%d", &n)) printf("ERRO: leitura incorreta do tamanho do vetor\n");
    vetor v = malloc (n * sizeof (int));
    INTgetVetor (v, n);
    INTprintaVetor (v, n);
    INTinsertionSort (v, n);
    INTprintaVetor (v, n);
}