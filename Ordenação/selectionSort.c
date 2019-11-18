/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                             Ordenação por Seleção                                   //
//                                (Selection Sort)                                     //
//                                                                                     //
// Algoritmo de ordenação baseado na seguinte ideia:                                   //
// - Manter o começo do vetor ordenado (começa vazio)                                  //
// - Procurar o menor elemento da parte não ordenada                                   //
// - Colocar esse menor elemento no final da parte ordenada                            //
// - Repetir isso até que todos os elementos estejam na parte ordenada                 //
//                                                                                     //
// É um algoritmo de ordenação estável e consome tempo O(n^2) em qualquer caso.        //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "FunçõesAuxiliares/compara.h" // Funções de comparação pros tipos primitivos
#include "vetor.h" // Definição do vetor e troca()

#define v(i) ((char *) v + (i) * sz)

// Ordena o vetor v com a ordem estabelecida pela função compara
void selectionSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    int i, j, min;
    // Vai aumentando a parte ordenada
    for (i = 0; i < n; i++) {
        min = i;
        // Procura o menor elemento do resto
        for (j = i + 1; j < n; j++)
            if (compara (v(j), v(min)) < 0) min = j;
        // Coloca o menor na parte ordenada
        troca (v, i, min, sz);
    }
}

void INTselectionSort (vetor v, int n) { selectionSort (v, n, sizeof (int), INTcompara); }
void CHARselectionSort (vetor v, int n) { selectionSort (v, n, sizeof (char), CHARcompara); }
void FLOATselectionSort (vetor v, int n) { selectionSort (v, n, sizeof (float), FLOATcompara); }
void DOUBLEselectionSort (vetor v, int n) { selectionSort (v, n, sizeof (double), DOUBLEcompara); }