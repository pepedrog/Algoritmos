#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "vetor.h"
#include "SelectionSort/selectionSort.h"

int main (void) {
    int n;
    if (!scanf ("%d", &n)) printf("ERRO: leitura incorreta do tamanho do vetor\n");
    vetor v = malloc (n * sizeof (int));
    INTgetVetor (v, n);
    INTprintaVetor (v, n);
    INTselectionSort (v, n);
    INTprintaVetor (v, n);
}