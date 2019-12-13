#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../vetor.h"

int main (int argc, char *argv[]) {
    int n, k;

    clock_t t;
    scanf ("%d %d", &n, &k);
    //vetor v = iniciaVetor (n, sizeof (int));
    vetor v = INTaleatorio (n, 0, k);

    // INTgetVetor (v, n);
    // INTprintaVetor (v, n);

    vetor ordena = clonaVetor (v, n, sizeof (int));
    
    t = clock();
    ordenaTipo(ordena, n, int, quickSort);
    printf ("QuickSort 0:   %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(ordena, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(ordena, n, int, quickSortOtim1);
    printf ("QuickSort 1:   %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(ordena, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(ordena, n, int, quickSortOtim2);
    printf ("QuickSort 2:   %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(ordena, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(ordena, n, int, quickSortOtim3);
    printf ("QuickSort 3:   %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(ordena, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(ordena, n, int, qsort);
    printf ("QuickSort C:   %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(ordena, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    
    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(ordena, n, int, mergeSort);
    printf ("MergeSort:     %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(ordena, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(ordena, n, int, heapSort);
    printf ("HeapSort:      %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(ordena, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n"), INTprintaVetor(ordena, n);

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    countingSort((int *) ordena, n, k);
    printf ("CountingSort:  %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(ordena, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    t = clock();
    ordenaTipo(ordena, n, int, selectionSort);
    printf ("SelectionSort: %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(ordena, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(ordena, n, int, insertionSort);
    printf ("InsertionSort: %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(ordena, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(ordena, n, int, cocktailSort);
    printf ("CocktailSort:  %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(ordena, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(ordena, n, int, bubbleSort);
    printf ("BubbleSort:    %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(ordena, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    free (ordena);
    free (v);
}
