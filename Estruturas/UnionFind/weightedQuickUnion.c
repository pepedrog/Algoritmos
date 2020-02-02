/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                                 Union Find                                          //
//                         Versão Weighted Quick Union                                 //
//                            aka Ranked Quick Union                                   //
//                                                                                     //
// Nessa implementação, é feito uma busca numa árvore de ids, até que o id do elemento //
// seja ele mesmo (raiz da árvore)                                                     //
// Dois elementos i e j estão conectados somente se esse processo de busca conduzir a  //
// a uma mesma raíz.                                                                   //
//                                                                                     //
// A versão Weighted Quick-Union faz a operação Find e Union em O(lg(n)).              //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "unionFind.h"
#include <stdlib.h> // malloc

// Aloca um UF na memória e inicializa com n conjuntos unitários
WQU criaWQU (int n) {
    WQU novo = malloc (sizeof (struct wqu));
    novo->n = n;
    novo->id = malloc (n * sizeof (int));
    novo->sz = malloc (n * sizeof (int));
    while (n--) {
        novo->id[n] = n;
        novo->sz[n] = 1;
    }
    return novo;
}

// Devolve o identificador do conjunto do elemento i no Union Find UF
int findWQU (WQU UF, int i) {
    // Sobe a árvore até a raiz
    while (i != UF->id[i])
        i = UF->id[i];
    return i;
}

// Conecta os elementos i e j no UnionFind UF
void unionWQU (WQU UF, int i, int j) {
    i = findWQU (UF, i);
    j = findWQU (UF, j);
    if (i == j) return;
    // Conecta o menor no maior
    if (UF->sz[i] > UF->sz[j]) {
        UF->id[j] = i;
        UF->sz[i] += UF->sz[j];
    }
    else {
        UF->id[i] = j;
        UF->sz[j] += UF->sz[i];
    }
}
