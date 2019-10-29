#include "../FunçõesAuxiliares/compara.h" // Funções de comparação pros tipos primitivos
#include "../vetor.h" // Definião do vetor e troca()

#define v(i) ((char *) v + i * sz)

// Ordena o vetor v com a ordem estabelecida pela função compara
void selectionSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {

    int i; // Primeiro índice da parte não ordenada
    int j; // Iterador sob a parte não ordenada
    int min; // Guarda o menor elemento da parte não ordenada
    // Vai aumentando a parte ordenada, até ser o vetor inteiro
    for (i = 0; i < n; i++) {

        min = i;
        // Percorre a parte não ordenada procurando o menor elemento
        for (j = i + 1; j < n; j++)
            // Se j < min, min = j

            printf ("comparando %d com %d\n", *((int *) v(j)), *((int *) v(min)));
            if (compara (v(j), v(min)) < 0) printf(" j < min\n"), min = j;
        // Coloca mínimo na parte ordenada
        printf ("colocando %d na parte ordenada\n", *((int *) v(min)));
        troca (v, i, min, sz);  
    }
}

void INTselectionSort (vetor v, int n) {
    selectionSort (v, n, sizeof (int), INTcompara);
}

void FLOATselectionSort (vetor v, int n) {
    selectionSort (v, n, sizeof (int), FLOATcompara);
}

void DOUBLEselectionSort (vetor v, int n) {
    selectionSort (v, n, sizeof (int), DOUBLEcompara);
}

void CHARselectionSort (vetor v, int n) {
    selectionSort (v, n, sizeof (int), CHARcompara);
}