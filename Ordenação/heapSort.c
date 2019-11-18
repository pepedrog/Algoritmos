/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                        Ordenação por Heap (Empilhamento ?)                          //
//                                  (Heap Sort)                                        //
//                                                                                     //
// Algoritmo de ordenação baseado na seguinte ideia:                                   //
// - Transformar o vetor num heap                                                      //
// - Fazer um selectionSort:                                                           //
// - Selecionar o maior e colocar no final do vetor                                    //
// - Repetir até que todos já tenham sido selecionados                                 //
//                                                                                     //
// É um algoritmo não estável e consome tempo O(n log(n)) em qualquer caso             //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "FunçõesAuxiliares/compara.h" // Funções de comparação pros tipos primitivos
#include "vetor.h" // Definição do vetor e troca()
#include <stdio.h>
typedef vetor heap;

#define v(i) ((char *) v + (i) * sz)
#define h(i) ((char *) h + (i) * sz)
int isheap (heap h, int n, size_t sz, int (*compara) (const void *, const void *)) {
    for (int i = 0; i < n; i++) {
        int pai = i;
        int filho1 = 2*i + 1;
        int filho2 = 2*i + 2;
        if (filho1 < n && compara(h(pai), h(filho1)) < 0){ printf ("pai %d menor que %d\n", *((int *)(h(pai))), *((int *)(h(filho1)))); return 0;}
        if (filho2 < n && compara(h(pai), h(filho2)) < 0){ printf ("pai %d menor que %d\n", *((int *)(h(pai))), *((int *)(h(filho2)))); return 0;}

    }
    return 1;
}

// Transforma o vetor em um max-heap
void heapfica (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));

// Atualiza o heap rebaixando o primeiro elemento (decrease)
void rebaixa (heap h, int n, size_t sz, int (*compara) (const void *, const void *));

// Atualiza o heap elevando o último elemento
void eleva (heap h, int n, size_t sz, int (*compara) (const void *, const void *));

// Ordena o vetor v com a ordem estabelecida pela função compara
void heapSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    heapfica (v, n, sz, compara);
    while (n--) {
        troca (v, 0, n, sz);
        rebaixa (v, n, sz, compara);
    }
}

void heapfica (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    // Considera o final do vetor um heap e vai crescendo ele
    for (int i = 0; i < n; i++)
        eleva (v, i + 1, sz, compara);
}

void rebaixa (heap h, int n, size_t sz, int (*compara) (const void *, const void *)) {
    int pai = 0, filho = 1;
    while (filho < n) {
        // Se o pai for menor que o filho, troca
        if (filho + 1 < n && compara (h(filho), h(filho + 1)) < 0) filho++;
        if (compara (h(pai), h(filho)) > 0) return;
        troca (h, pai, filho, sz);
        pai = filho;
        filho = 2*pai + 1;
    }
}

void eleva (heap h, int n, size_t sz, int (*compara) (const void *, const void *)) {
    int filho = n - 1;
    int pai = (filho - 1) / 2;
    while (filho > 0) {
        // Se o pai for menor que o filho, troca
        if (compara (h(pai), h(filho)) > 0) return;
        troca (h, pai, filho, sz);
        filho = pai;
        pai = (filho - 1) / 2;
    }
}

void INTheapSort (vetor v, int n) {
    heapSort (v, n, sizeof (int), INTcompara);
}

void FLOATheapSort (vetor v, int n) {
    heapSort (v, n, sizeof (float), FLOATcompara);
}

void DOUBLEheapSort (vetor v, int n) {
    heapSort (v, n, sizeof (double), DOUBLEcompara);
}

void CHARheapSort (vetor v, int n) {
    heapSort (v, n, sizeof (char), CHARcompara);
}