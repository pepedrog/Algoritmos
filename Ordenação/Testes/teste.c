#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../vetor.h"
#include "../FunçõesAuxiliares/compara.h"

int main (int argc, char *argv[]) {
    int n, m;

    clock_t t;
    printf ("\n");
    scanf ("%d %d", &n, &m);
    //vetor v = iniciaVetor (n, sizeof (int));
    vetor v = INTaleatorio (n, 0, m);

    // INTgetVetor (v, n);
    // INTprintaVetor (v, n);

    vetor ordena = clonaVetor (v, n, sizeof (int));
    
    t = clock();
    ordenaTipo(v, n, int, quickSort);
    printf ("QuickSort 0:   %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(v, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(v, n, int, quickSortOtim1);
    printf ("QuickSort 1:   %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(v, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(v, n, int, quickSortOtim2);
    printf ("QuickSort 2:   %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(v, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(v, n, int, quickSortOtim3);
    printf ("QuickSort 3:   %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(v, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(v, n, int, qsort);
    printf ("QuickSort C:   %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(v, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    
    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(v, n, int, mergeSort);
    printf ("MergeSort:     %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(v, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(v, n, int, heapSort);
    printf ("HeapSort:      %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(v, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n"), INTprintaVetor(ordena, n);

    t = clock();
    ordenaTipo(v, n, int, selectionSort);
    printf ("SelectionSort: %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(v, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(v, n, int, insertionSort);
    printf ("InsertionSort: %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(v, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(v, n, int, cocktailSort);
    printf ("CocktailSort:  %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(v, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    ordenaTipo(v, n, int, bubbleSort);
    printf ("BubbleSort:    %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(v, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    free (ordena);
    free (v);
}