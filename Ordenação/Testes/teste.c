#include <stdio.h> // scanf
#include <time.h> // pra medir o tempo da ordenação
#include "../vetor.h"

int main (void) {
    int n;
    clock_t t;
    scanf ("%d", &n);
    //vetor v = iniciaVetor (n, sizeof (int));
    vetor v = INTaleatorio (n, 0, 1000);

    // INTgetVetor (v, n);
    // INTprintaVetor (v, n);

    vetor ordena = clonaVetor (v, n, sizeof (int));
    t = clock();
    INTselectionSort (ordena, n);
    printf ("SelectionSort: %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    INTinsertionSort (ordena, n);
    printf ("InsertionSort: %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    INTbubbleSort (ordena, n);
    printf ("BubbleSort: %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
}