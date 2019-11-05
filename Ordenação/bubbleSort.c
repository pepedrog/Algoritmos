/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                             Ordenação por Flutuação                                 //
//                                  (Bubble Sort)                                      //
//                                                                                     //
// Algoritmo de ordenação baseado na seguinte ideia:                                   //
// - Empurrar algum elemento pro final do vetor até que ele esbarre em alguem maior    //
// - Depois, parar de empurrar esse elemento e empurrar o elemento maior               //
// - Repetir esse processo até 'flutuar' o maior elemento pro final do vetor           //
// - Repetir até que todos os elementos já tenham flutuado pro seu devido lugar        //
//                                                                                     //
// É um algoritmo de ordenação estável e consome tempo O(n^2) no caso medio e          //
// O(n) no melhor caso (vetor já ordenado ou quase).                                   //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "FunçõesAuxiliares/compara.h" // Funções de comparação pros tipos primitivos
#include "vetor.h" // Definição do vetor e troca()

#define v(i) ((char *) v + (i) * sz)

// Ordena o vetor v com a ordem estabelecida pela função compara
void bubbleSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    for (int fim = n; fim > 0; fim--)
        // Vai flutuando até chegar no fim
        for (int i = 1; i < fim; i++)
            if (compara (v(i - 1), v(i)) > 0)
                troca (v, i - 1, i, sz);
}

void INTbubbleSort (vetor v, int n) {
    bubbleSort (v, n, sizeof (int), INTcompara);
}

void FLOATbubbleSort (vetor v, int n) {
    bubbleSort (v, n, sizeof (float), FLOATcompara);
}

void DOUBLEbubbleSort (vetor v, int n) {
    bubbleSort (v, n, sizeof (double), DOUBLEcompara);
}

void CHARbubbleSort (vetor v, int n) {
    bubbleSort (v, n, sizeof (char), CHARcompara);
}