#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../vetor.h"

// Macro muito util pra não recopiar esse trecho pra cada função
#define processa(nome)             \
    copiaVetor (ordena, v, n, sizeof (int)); \
    t = clock();                    \
    ordenaTipo(ordena, n, int, nome); \
    printf ("%20s:  \t%fs\n", #nome, (clock() - t) / (float) CLOCKS_PER_SEC); \
    if (!ordenaTipo(ordena, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n")

void printaInstrucoes () {
    printf("Exemplo de uso: ./teste n=10000 k_min=0 k_max=1000\n");
}

// Le os argumentos da linha de comando
void leArgumentos (int argc, char *argv[], int *n, int *k_min, int *k_max) {
    char *arg;
    for (int i = 1; i < argc; i++)
        if (argv[i][0] == 'n') {
            arg = &argv[i][2];
            *n = atoi (arg);
        }
        else if (argv[i][0] == 'k') {
            arg = &argv[i][5];
            if (argv[i][3] == 'i') *k_min = atoi (arg);
            else if (argv[i][3] == 'a') *k_max = atoi (arg);
            else printaInstrucoes();
        }
        else printaInstrucoes();
}

int main (int argc, char *argv[]) {
    int n = 10000, k_min = 0, k_max = 10000;
    leArgumentos(argc, argv, &n, &k_min, &k_max);
    clock_t t;
    
    vetor v = INTaleatorio (n, k_min, k_max);
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
    countingSort((int *) ordena, n, k_max);
    printf ("        countingSort:\t%fs\n", (clock() - t) / (float) CLOCKS_PER_SEC);
    if (!ordenaTipo(ordena, n, int, estaOrdenado)) printf ("ERRO: vetor não ordenado\n");

    processa(shellSort1);
    processa(shellSort2);
    processa(shellSort3);
    processa(selectionSort);
    processa(insertionSort);
    processa(cocktailSort);
    processa(bubbleSort);

    free (ordena);
    free (v);
}
