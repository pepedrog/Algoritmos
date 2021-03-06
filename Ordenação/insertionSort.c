/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                             Ordenação por Inserção                                  //
//                                (Insertion Sort)                                     //
//                                                                                     //
// Algoritmo de ordenação baseado na seguinte ideia:                                   //
// - Manter o começo do vetor ordenado (começa vazio)                                  //
// - Inserir o primeiro elemento da parte não ordenada na parte ordenada               //
// - Repetir isso até que todos os elementos estejam na parte ordenada                 //
//                                                                                     //
// É um algoritmo de ordenação estável e consome tempo O(n^2) no caso medio e          //
// O(n) no melhor caso (vetor já ordenado ou quase).                                   //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "vetor.h" // Definião do vetor e troca()
#include <stdlib.h> // malloc()

#define v(i) ((char *) v + (i) * sz)

// Ordena o vetor v com a ordem estabelecida pela função compara
void insertionSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    int i, j;
    void *atual = malloc (sz);
    // Vamos inserir v[i] na parte ordenada
    for (i = 1; i < n; i++) {
        copiaMemoria (atual, v(i), sz);
        // Empurra os elementos pra esquerda até chegar na posição do inserido
        for (j = i - 1; j >= 0 && compara(v(j), atual) > 0; j--)
            copia(v, j + 1, j, sz);
        copiaMemoria (v(j + 1), atual, sz);
    }
    free (atual);
}
