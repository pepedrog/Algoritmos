/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                           Ordenação por Intercalação                                //
//                                  (Merge Sort)                                       //
//                                                                                     //
// Algoritmo de ordenação baseado na seguinte ideia:                                   //
// - Dividir o vetor em duas metades                                                   //
// - Ordenar cada metade                                                               //
// - Intercalar as duas                                                                //
//                                                                                     //
// É um algoritmo de ordenação estável e consome tempo O(n log(n)) em qualquer caso.   //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "FunçõesAuxiliares/compara.h" // Funções de comparação pros tipos primitivos
#include "vetor.h" // Definição do vetor e troca()
#include <stdlib.h> // free()

#define v(i) ((char *) v + (i) * sz)
#define aux(i) ((char *) aux + (i) * sz)

// Função recursiva que realmente faz a ordenação
void mergeSortRec (vetor v, int ini, int fim, size_t sz, int (*compara) (const void *, const void *));

// Função que intercala a primeira metade com a segunda metade
void merge (vetor v, int ini, int fim, size_t sz, int (*compara) (const void *, const void *));

// Ordena o vetor v com a ordem estabelecida pela função compara
// Função handler do mergeSort
void mergeSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    mergeSortRec (v, 0, n, sz, compara);
}

void mergeSortRec (vetor v, int ini, int fim, size_t sz, int (*compara) (const void *, const void *)) {
    // Base da recursão, vetor unitario
    if (ini == fim - 1) return;
    int meio = (ini + fim) / 2;
    // Ordena as duas metades
    mergeSortRec (v, ini, meio, sz, compara);
    mergeSortRec (v, meio, fim, sz, compara);
    // Intercala
    merge (v, ini, fim, sz, compara);
}

void merge (vetor v, int ini, int fim, size_t sz, int (*compara) (const void *, const void *)) {
    vetor aux = iniciaVetor (fim - ini, sz);
    int meio = (ini + fim) / 2;
    int ini1 = ini;
    int ini2 = meio;
    int atual = 0;
    // Enquanto nenhuma das duas metades acabar
    while (ini1 < meio && ini2 < fim) {
        if (compara (v(ini1), v(ini2)) > 0) atribui (aux, atual, sz, v(ini2++));
        else atribui (aux, atual, sz, v(ini1++));
        atual++;
    }
    // Copia a metade que ainda não acabou pro final do vetor
    while (ini1 < meio) atribui (aux, atual++, sz, v(ini1++));
    while (ini2 < fim) atribui (aux, atual++, sz, v(ini2++));
    // Copia o aux no vetor
    atual = 0;
    while (ini < fim) atribui (v, ini++, sz, aux(atual++));
    free (aux);
}

void INTmergeSort (vetor v, int n) {
    mergeSort (v, n, sizeof (int), INTcompara);
}

void FLOATmergeSort (vetor v, int n) {
    mergeSort (v, n, sizeof (float), FLOATcompara);
}

void DOUBLEmergeSort (vetor v, int n) {
    mergeSort (v, n, sizeof (double), DOUBLEcompara);
}

void CHARmergeSort (vetor v, int n) {
    mergeSort (v, n, sizeof (char), CHARcompara);
}