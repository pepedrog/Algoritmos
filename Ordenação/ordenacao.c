#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* endereco;

// Troca o conteúdo (t bytes) de dois endereços de memória
void troca (endereco a, endereco b, size_t t) {
    endereco aux = malloc (t);
    memcpy (aux, a, t);
    memcpy (a, b, t);
    memcpy (b, aux, t);
}

void INTprintaVetor (int *v, int n) {
    for (int i = 0; i < n; i++) printf( "%d\t", v[i]);
    puts("\n");
}

int INTcompara (endereco a, endereco b) {
    int ai = *((int *) a);
    int bi = *((int *) b);
    return ai - bi;
}

void selectionSort (endereco v, int n, size_t sz, int (*compara)( endereco, endereco)) {
    int i, min, j;
    // Percorre o vetor
    for (i = 0; i < n; i++) {
        min = i;
        // Percorre a parte não ordenada procurando o menor elemento
        for (j = i + 1; j < n; j++)
            if (compara ((char *) v + j * sz, (char *) v + min * sz) < 0) min = j;
        // Coloca o menor elemento na parte ordenada
        // troca(v[i],v[min]) em notação void*
        troca ((char *) v + i * sz, (char *) v + min * sz, sz);     
    }
}

// Selection Sort -> Ordenação por inserção
void INTselectionSort (int* v, int n) {
    selectionSort (v, n, sizeof( int), INTcompara);
}

int main (int argc, char* argv[]) {
    int v[10] = { 10, 3, 5, 10, 25, 35, 7, 2, 5, 1};
    INTprintaVetor (v, 10);
    INTselectionSort (v, 10);
    INTprintaVetor (v, 10);

}