/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                              Ordenação por Contagem                                 //
//                                 (Counting Sort)                                     //
//                                                                                     //
// Algoritmo de ordenação baseado na seguinte ideia:                                   //
// - Receber um vetor de **inteiros** cujo maior elemento é k                          //
// - Percorrer o vetor contando quantas vezes cada inteiro aparece                     //
// - Reconstruir o vetor colocando a quantidade de cada inteiro em ordem               //
//                                                                                     //
// É um algoritmo de ordenação que consome tempo e espaço O(k*n) (pseudo-polinomial)   //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "vetor.h" // iniciaVetor()
#include <stdlib.h> // free()

// Ordena o vetor de inteiros v cujo maior elemento é k
void countingSort (int* v, int n, int k) {
    int i, j = 0;
    int * contador = iniciaVetor(k + 1, sizeof(int));
    for (i = 0; i <= k; i++) contador[i] = 0;
    for (i = 0; i < n; i++) contador[v[i]]++;
    for (i = 0; i <= k; i++)
        while (contador[i]--) v[j++] = i;
    free (contador);
}
