/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                             Ordenação por Inserção                                  //
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

#include "../FunçõesAuxiliares/compara.h" // Funções de comparação pros tipos primitivos
#include "../vetor.h" // Definião do vetor e troca()
#include <stdlib.h> // malloc()

#define v(i) ((char *) v + (i) * sz)

// Equivalente a memcpy(), implementado em manipula.c
void copiaMemoria (char *dest, char *ori, size_t sz);

// Ordena o vetor v com a ordem estabelecida pela função compara
void insertionSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {

    int i, j;
    void *guardai = malloc (sz);

    // Vamos inserir v[i] na parte ordenada
    for (i = 1; i < n; i++) {
        // Guarda o valor de v[i]
        copiaMemoria (guardai, v(i), sz);
        j = i - 1;
        // Vai empurrando os elementos pra esquerda até chegar na posição do i
        while (j >= 0 && compara(v(j), guardai) > 0) {
            copia(v, j + 1, j, sz);
            j--;
        }
        // Coloca o v[i] no lugar dele
        copiaMemoria (v(j + 1), guardai, sz);
    }
}

void INTinsertionSort (vetor v, int n) {
    insertionSort (v, n, sizeof (int), INTcompara);
}

void FLOATinsertionSort (vetor v, int n) {
    insertionSort (v, n, sizeof (int), FLOATcompara);
}

void DOUBLEinsertionSort (vetor v, int n) {
    insertionSort (v, n, sizeof (int), DOUBLEcompara);
}

void CHARinsertionSort (vetor v, int n) {
    insertionSort (v, n, sizeof (int), CHARcompara);
}