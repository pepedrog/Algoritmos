#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../vetor.h"

int main (void) {
    int n;
    clock_t t;
    scanf ("%d", &n);
    //vetor v = iniciaVetor (n, sizeof (int));
    vetor v = INTaleatorio (n, 0, 9000);

    // INTgetVetor (v, n);
    // INTprintaVetor (v, n);

    vetor ordena = clonaVetor (v, n, sizeof (int));
    t = clock();
    INTselectionSort (ordena, n);
    printf ("SelectionSort: %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!INTestaOrdenado (ordena, n)) printf ("ERRO: vetor não ordenado");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    INTinsertionSort (ordena, n);
    printf ("InsertionSort: %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!INTestaOrdenado (ordena, n)) printf ("ERRO: vetor não ordenado");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    INTbubbleSort (ordena, n);
    printf ("BubbleSort: %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!INTestaOrdenado (ordena, n)) printf ("ERRO: vetor não ordenado");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    INTcocktailSort (ordena, n);
    printf ("CocktailSort: %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!INTestaOrdenado (ordena, n)) printf ("ERRO: vetor não ordenado");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    INTmergeSort (ordena, n);
    printf ("MergeSort: %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!INTestaOrdenado (ordena, n)) printf ("ERRO: vetor não ordenado");

    free (ordena);
    free (v);
}