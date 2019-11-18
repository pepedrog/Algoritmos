#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../vetor.h"
#include "../FunçõesAuxiliares/compara.h"

int main (void) {
    int n;
    clock_t t;
    scanf ("%d", &n);
    //vetor v = iniciaVetor (n, sizeof (int));
    vetor v = INTaleatorio (n, 0, 100);

    // INTgetVetor (v, n);
    // INTprintaVetor (v, n);

    vetor ordena = clonaVetor (v, n, sizeof (int));
    /*
    t = clock();
    INTquickSort (ordena, n);
    printf ("QuickSort 0:   %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!INTestaOrdenado (ordena, n)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    INTquickSortOtim1 (ordena, n);
    printf ("QuickSort 1:   %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!INTestaOrdenado (ordena, n)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    INTquickSortOtim2 (ordena, n);
    printf ("QuickSort 2:   %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!INTestaOrdenado (ordena, n)) printf ("ERRO: vetor não ordenado\n");
*/
    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    INTquickSortOtim3 (ordena, n);
    printf ("QuickSort 3:   %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!INTestaOrdenado (ordena, n)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    qsort (ordena, n, sizeof (int), INTcompara);
    printf ("QuickSort C:   %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!INTestaOrdenado (ordena, n)) printf ("ERRO: vetor não ordenado\n");

    
    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    INTmergeSort (ordena, n);
    printf ("MergeSort:     %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!INTestaOrdenado (ordena, n)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    INTheapSort (ordena, n);
    printf ("HeapSort:      %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!INTestaOrdenado (ordena, n)) printf ("ERRO: vetor não ordenado\n"), INTprintaVetor(ordena, n);

    t = clock();
    INTselectionSort (ordena, n);
    printf ("SelectionSort: %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!INTestaOrdenado (ordena, n)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    INTinsertionSort (ordena, n);
    printf ("InsertionSort: %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!INTestaOrdenado (ordena, n)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    INTcocktailSort (ordena, n);
    printf ("CocktailSort:  %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!INTestaOrdenado (ordena, n)) printf ("ERRO: vetor não ordenado\n");

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    INTbubbleSort (ordena, n);
    printf ("BubbleSort:    %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!INTestaOrdenado (ordena, n)) printf ("ERRO: vetor não ordenado\n");

    free (ordena);
    free (v);
}