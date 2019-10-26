#include <stdlib.h>
#include <stdio.h>
#include "vetor.h"

int main (void) {
    int n;
    if (!scanf ("%d", &n)) printf("ERRO: leitura incorreta do tamanho do vetor\n");
    vetor v = malloc (n * sizeof (int));
    INTgetVetor (v, n);
    INTprintaVetor (v, n);
}