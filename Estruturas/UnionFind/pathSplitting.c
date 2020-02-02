/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                                 Union Find                                          //
//                       Versão Weighted Quick Union com                               //
//                               Path Splitting                                        //
//                                                                                     //
// Nessa implementação, é feito uma busca numa árvore de ids, até que o id do elemento //
// seja ele mesmo (raiz da árvore)                                                     //
// Dois elementos i e j estão conectados somente se esse processo de busca consuzir a  //
// a uma mesma raíz.                                                                   //
//                                                                                     //
// O algoritmo faz que, a cada busca, os caminhos da árvore sejam comprimidos por      //
// 1/4 do tamanho, fazendo as próximas buscas serem muito mais rápidas.                //
//                                                                                     //
// Essa versão faz a operação Find e Union em O(lg*(n)), que é na prática O(1).        //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "unionFind.h"
#include <stdlib.h> // malloc

// Aloca um UF na memória e inicializa com n conjuntos unitários
QUPS criaQUPS (int n) {
    QUPS novo = malloc (sizeof (struct qups));
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
int findQUPS (QUPS UF, int i) {
    int pai;
    // Sobe a árvore até a raiz
    while (i != UF->id[i]) {
        pai = UF->id[i];
        UF->id[i] = UF->id[pai]; // Path Splitting, reduz a altura em 4
        UF->id[pai] = UF->id[UF->id[pai]];
        i = UF->id[i];
    }
    return i;
}

// Conecta os elementos i e j no UnionFind UF
void unionQUPS (QUPS UF, int i, int j) {
    i = findQUPS (UF, i);
    j = findQUPS (UF, j);
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
