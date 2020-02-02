#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../vetor.h"

// Macro muito util pra não recopiar esse trecho pra cada função
#define processa(nome)             \
    copiaVetor (ordena, v, n, sizeof (int)); \
    t = clock();                    \
    ordenaTipo(ordena, n, int, nome); \
    printf ("%s:  \t%fs\n", #nome, (clock() - t) / (float) CLOCKS_PER_SEC); \
    if (!ordenaTipo(ordena, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n")

int main (int argc, char *argv[]) {
    int n, k;

    clock_t t;
    scanf ("%d %d", &n, &k);
    //vetor v = iniciaVetor (n, sizeof (int));
    vetor v = INTaleatorio (n, 0, k);

    // INTgetVetor (v, n);
    // INTprintaVetor (v, n);

    vetor ordena = clonaVetor (v, n, sizeof (int));
    
    processa(quickSort);
    processa(quickSortOtim1);
    processa(quickSortOtim2);
    processa(quickSortOtim3);
    processa(qsort);
    processa(mergeSort);
    processa(heapSort);

    copiaVetor (ordena, v, n, sizeof (int));
    t = clock();
    countingSort((int *) ordena, n, k);
    printf ("CountingSort:  %fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(ordena, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    
    processa(selectionSort);
    processa(insertionSort);
    processa(cocktailSort);
    processa(bubbleSort);

    free (ordena);
    free (v);
}
