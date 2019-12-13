/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                                Ordenação Rápida                                     //
//                                  (Quick Sort)                                       //
//                                                                                     //
// Algoritmo de ordenação baseado na seguinte ideia:                                   //
// - Dividir o vetor em duas partes, separadas por um pivô                             //
// - A primeira parte com elementos estritamente menores que a segunda                 //
// - Ordenar cada parte recursivamente                                                 //
//                                                                                     //
// É um algoritmo de ordenação estável (?) e consome tempo O(n log(n)) no caso         //
// e O(n²) no pior caso.                                                               //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "vetor.h" // Definição do vetor e troca()
#include <stdlib.h> // rand()

#define MAX(A, B) (((A) > (B)) ? (A) : (B))

#define v(i) ((char *) v + (i) * sz)

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

/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                         OTIMIZAÇÕES PRÁTICAS DO QUICKSORT                           // 
//                                                                                     //
// Vamos tentar copiar o que acontece na qsort() da stdlib                             //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
// Otimização 1 - Sorteando o pivô                                                     //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

int particionaAleatorio (vetor v, int ini, int fim, size_t sz, int (*compara) (const void *, const void *)) {
    // Sorteia o pivo e coloca no começo
    troca (v, ini, ini + rand() / RAND_MAX * (fim - 1 - ini), sz);
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

void quickSortRecOtim1 (vetor v, int ini, int fim, size_t sz, int (*compara) (const void *, const void *)) {
    // Base da recursão, vetor unitario
    if (ini >= fim - 1) return;
    // Particiona o vetor (sortrando o pivo)
    int meio = particionaAleatorio (v, ini, fim, sz, compara);
    // Ordena as duas 'metades' (geralmente não têem o mesmo tamanho)
    // Ordena a maior metade primeiro, para pilha de recursão ficar menor
    quickSortRecOtim1 (v, ini, meio, sz, compara);
    quickSortRecOtim1 (v, meio + 1, fim, sz, compara);
}

void quickSortOtim1 (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    quickSortRecOtim1 (v, 0, n, sz, compara);
}

/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
// Otimização 2 - Diminuindo a pilha de recursão                                       //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

void quickSortRecOtim2 (vetor v, int ini, int fim, size_t sz, int (*compara) (const void *, const void *)) {
    // Base da recursão, vetor unitario
    if (ini >= fim - 1) return;
    // Particiona o vetor (sortrando o pivo)
    int meio = particionaAleatorio (v, ini, fim, sz, compara);
    // Ordena as duas 'metades' (geralmente não têem o mesmo tamanho)
    // Ordena a menor metade primeiro, para pilha de recursão ficar menor
    if (meio - ini < fim - meio) {
        quickSortRecOtim2 (v, ini, meio, sz, compara);
        quickSortRecOtim2 (v, meio + 1, fim, sz, compara);
    } else {
        quickSortRecOtim2 (v, meio + 1, fim, sz, compara);
        quickSortRecOtim2 (v, ini, meio, sz, compara);
    }
}

void quickSortOtim2 (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    quickSortRecOtim2 (v, 0, n, sz, compara);
}

/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
// Otimização 3 - Usando InsertionSort pra subvetores menores                          //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#define TAM_INSERT 50
void quickSortRecOtim3 (vetor v, int ini, int fim, size_t sz, int (*compara) (const void *, const void *)) {
    // Vetor pequeno -> insertionSort
    if (fim - ini < TAM_INSERT) {
        insertionSort (v(ini), fim - ini, sz, compara);
        return;
    }
    // Particiona o vetor (sortrando o pivo)
    int meio = particionaAleatorio (v, ini, fim, sz, compara);
    // Ordena as duas 'metades' (geralmente não têem o mesmo tamanho)
    // Ordena a menor metade primeiro, para pilha de recursão ficar menor
    if (meio - ini < fim - meio) {
        quickSortRecOtim3 (v, ini, meio, sz, compara);
        quickSortRecOtim3 (v, meio + 1, fim, sz, compara);
    } else {
        quickSortRecOtim3 (v, meio + 1, fim, sz, compara);
        quickSortRecOtim3 (v, ini, meio, sz, compara);
    }
}

void quickSortOtim3 (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    quickSortRecOtim3 (v, 0, n, sz, compara);
}

/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
// Otimização 4 - Implementar a própria pilha - dispensar a recursão                   //
// não farei aqui, código bastante confuso, checar a implementação do qsort:           //
// https://code.woboq.org/userspace/glibc/stdlib/qsort.c.html#_quicksort               //                                     //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////