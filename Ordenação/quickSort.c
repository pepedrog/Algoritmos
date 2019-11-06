/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                                Ordenação Rápida                                     //
//                                  (Quick Sort)                                       //
//                                                                                     //
// Algoritmo de ordenação baseado na seguinte ideia:                                   //
// - Dividir o vetor em duas partes, separadas por um pivô                             //
// - A primeira parte com elementos estritamente menores que que segunda               //
// - Ordenar cada parte                                                                //
//                                                                                     //
// É um algoritmo de ordenação estável e consome tempo O(n log(n)) no caso             //
// e O(n²) no pior caso.                                                               //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "FunçõesAuxiliares/compara.h" // Funções de comparação pros tipos primitivos
#include "vetor.h" // Definição do vetor e troca()
#include <stdlib.h> // free()

#define v(i) ((char *) v + (i) * sz)
#define aux(i) ((char *) aux + (i) * sz)

// Função recursiva que realmente faz a ordenação
void quickSortRec (vetor v, int ini, int fim, size_t sz, int (*compara) (const void *, const void *));

// Função que divide o vetor em duas partes e devolve o índice da divisão (pivô)
int particiona (vetor v, int ini, int fim, size_t sz, int (*compara) (const void *, const void *));

// Ordena o vetor v com a ordem estabelecida pela função compara
// Função handler do quickSort
void quickSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    quickSortRec (v, 0, n, sz, compara);
}

void quickSortRec (vetor v, int ini, int fim, size_t sz, int (*compara) (const void *, const void *)) {
    // Base da recursão, vetor unitario
    if (ini >= fim - 1) return;
    // Particiona o vetor
    int meio = particiona (v, ini, fim, sz, compara);
    // Ordena as duas 'metades' (geralmente não têem o mesmo tamanho)
    quickSortRec (v, ini, meio, sz, compara);
    quickSortRec (v, meio + 1, fim, sz, compara);

}

int particiona (vetor v, int ini, int fim, size_t sz, int (*compara) (const void *, const void *)) {
    int i = ini + 1;
    // O pivo será o v[ini], por padrão
    // Coloca todos os elementos menores que o pivo no começo do vetor
    for (int j = ini + 1; j < fim; j++)
        if (compara (v(j), v(ini)) < 0)
            troca (v, i++, j, sz);
    // Põe o pivo no meio
    troca (v, ini, i - 1, sz);
    return i - 1;
}

void INTquickSort (vetor v, int n) {
    quickSort (v, n, sizeof (int), INTcompara);
}

void FLOATquickSort (vetor v, int n) {
    quickSort (v, n, sizeof (float), FLOATcompara);
}

void DOUBLEquickSort (vetor v, int n) {
    quickSort (v, n, sizeof (double), DOUBLEcompara);
}

void CHARquickSort (vetor v, int n) {
    quickSort (v, n, sizeof (char), CHARcompara);
}