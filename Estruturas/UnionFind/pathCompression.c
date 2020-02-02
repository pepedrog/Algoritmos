/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                                 Union Find                                          //
//                       Versão Weighted Quick Union com                               //
//                              Path Compression                                       //
//                                                                                     //
// Nessa implementação, é feito uma busca numa árvore de ids, até que o id do elemento //
// seja ele mesmo (raiz da árvore)                                                     //
// Dois elementos i e j estão conectados somente se esse processo de busca consuzir a  //
// a uma mesma raíz.                                                                   //
//                                                                                     //
// O algoritmo faz que, a cada busca, os caminhos da árvore sejam comprimidos por      //
// completo, fazendo as próximas buscas serem muito mais rápidas.                      //
//                                                                                     //
// Essa versão faz a operação Find e Union em O(lg*(n)), que é na prática O(1).        //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "unionFind.h"
#include <stdlib.h> // malloc

// Aloca um UF na memória e inicializa com n conjuntos unitários
QUPC criaQUPC (int n) {
    QUPC novo = malloc (sizeof (struct qupc));
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
int findQUPC (QUPC UF, int i) {
    int aux;
    int j = i;
    // Sobe a árvore até a raiz
    while (i != UF->id[i])
        i = UF->id[i];
    // Path compression
    while (j != i) {
        aux = UF->id[j];
        UF->id[j] = i;
        j = aux;
    }
    return i;
}

// Conecta os elementos i e j no UnionFind UF
void unionQUPC (QUPC UF, int i, int j) {
    i = findQUPC (UF, i);
    j = findQUPC (UF, j);
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
