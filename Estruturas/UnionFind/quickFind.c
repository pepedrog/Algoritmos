/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                                 Union Find                                          //
//                              Versão Quick Find                                      //
//                                                                                     //
// Nessa implementação, dois elementos i e j estão conectados somente se id[i] = id[j] //
// A versão Quick-Find faz a operação Find em O(1) e Union em O(n).                    //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "unionFind.h"
#include <stdlib.h> // malloc

// Aloca um UF na memória e inicializa com n conjuntos unitários
QF criaQF (int n) {
    QF novo = malloc (sizeof (struct qf));
    novo->n = n;
    novo->id = malloc (n * sizeof (int));
    while (n--)
        novo->id[n] = n;
    return novo;
}

// Devolve o identificador do conjunto do elemento i no Union Find UF
int findQF (QF UF, int i) {
    return UF->id[i];
}

// Conecta os elementos i e j no UnionFind UF
void unionQF (QF UF, int i, int j) {
    int id_i = UF->id[i];
    // Faz todo mundo que apontava pro id[i] apontar pro id[j]
    for (int k = 0; k < UF->n; k++)
        if (UF->id[k] == id_i) UF->id[k] = UF->id[j];
}