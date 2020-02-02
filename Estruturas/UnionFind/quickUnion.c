/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                                 Union Find                                          //
//                              Versão Quick Find                                      //
//                                                                                     //
// Nessa implementação, é feito uma busca numa árvore de ids, até que o id do elemento //
// seja ele mesmo (raiz da árvore)                                                     //
// Dois elementos i e j estão conectados somente se esse processo de busca consuzir a  //
// a uma mesma raíz.                                                                   //
//                                                                                     //
// A versão Quick-Union faz a operação Find e Union em O(n).                           //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "unionFind.h"
#include <stdlib.h> // malloc

// Aloca um UF na memória e inicializa com n conjuntos unitários
QU criaQU (int n) {
    QU novo = malloc (sizeof (struct qu));
    novo->n = n;
    novo->id = malloc (n * sizeof (int));
    while (n--)
        novo->id[n] = n;
    return novo;
}

// Devolve o identificador do conjunto do elemento i no Union Find UF
int findQU (QU UF, int i) {
    // Sobe a árvore até a raiz
    while (i != UF->id[i])
        i = UF->id[i];
    return i;
}

// Conecta os elementos i e j no UnionFind UF
void unionQU (QU UF, int i, int j) {
    UF->id[i] = findQU (UF, j);
}
