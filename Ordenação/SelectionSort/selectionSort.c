#include <stdio.h>
#include <stdlib.h>
#include "compara.h"
#include <string.h>

// Troca o conteúdo (t bytes) de dois endereços de memória
void troca (void * a, void * b, size_t t) {
    const void * aux = malloc (t);
    memcpy (aux, a, t);
    memcpy (a, b, t);
    memcpy (b, aux, t);
}

void selectionSort (void *v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    int i, min, j;
    // Percorre o vetor
    for (i = 0; i < n; i++) {
        min = i;
        // Percorre a parte não ordenada procurando o menor elemento
        for (j = i + 1; j < n; j++)
            // Se j < min, min = j
            if (compara ((char *) v + j * sz, (char *) v + min * sz) < 0) min = j;
        // Coloca o menor elemento na parte ordenada
        // troca(v[i],v[min]) em notação void*
        troca ((char *) v + i * sz, (char *) v + min * sz, sz);     
    }
}

// Selection Sort -> Ordenação por inserção
void INTselectionSort (int* v, int n) {
    selectionSort (v, n, sizeof (int), INTcompara);
}