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

typedef vetor heap;

#define v(i) ((char *) v + (i) * sz)
#define h(i) ((char *) h + (i) * sz)

// Transforma o vetor em um max-heap
void heapfica (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));

// Atualiza o heap rebaixando o primeiro elemento (decrease)
void rebaixa (heap h, int n, size_t sz, int (*compara) (const void *, const void *));

// Ordena o vetor v com a ordem estabelecida pela função compara
void heapSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    INTprintaVetor (v, n);
    heapfica (v, n, sz, compara);
    INTprintaVetor (v, n);
    while (n--) {
        troca (v, 0, n, sz);
        rebaixa (v, n, sz, compara);
    }
}
int isheap (heap h, int n, size_t sz, int (*compara) (const void *, const void *)) {
    for (int i = 0; i < n; i++) {
        int filho = i;
        if (filho % 2 == 1) filho ++;
        int pai = (filho / 2) - 1;
        while (pai >= 0) {
            printf ("filho é %d pai é %d\n", filho, pai);
            if (compara(h(pai), h(filho)) < 0) return 0;
            filho = pai;
            if (filho % 2 == 1) filho ++;
            int pai = (filho / 2) - 1;

            if (filho == 0) break;
        }
    }
    return 1;
}
void heapfica (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    // Considera o final do vetor um heap e vai crescendo ele
    for (int i = n - 1; i >= 0; i--) 
        rebaixa (v(i), n - i, sz, compara);
}

void rebaixa (heap h, int n, size_t sz, int (*compara) (const void *, const void *)) {
    INTprintaVetor (h, n);
    int pai = 0, filho = 1;
    while (filho < n) {
        // Se o pai for maior que o filho, troca
        if (filho + 1 < n && compara (h(filho), h(filho + 1)) < 0) filho++;
        if (compara (h(pai), h(filho)) > 0) return;
        troca (h, pai, filho, sz);
        pai = filho;
        filho = 2*pai + 1;
    }
    if (isheap (h, n, sz, compara)) printf ("AAA\n");
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