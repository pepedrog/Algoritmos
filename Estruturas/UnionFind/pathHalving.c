/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                                 Union Find                                          //
//                       Versão Weighted Quick Union com                               //
//                                Path Halving                                         //
//                                                                                     //
// Nessa implementação, é feito uma busca numa árvore de ids, até que o id do elemento //
// seja ele mesmo (raiz da árvore)                                                     //
// Dois elementos i e j estão conectados somente se esse processo de busca consuzir a  //
// a uma mesma raíz.                                                                   //
//                                                                                     //
// O algoritmo faz que, a cada busca, os caminhos da árvore sejam comprimidos pela     //
// metade, fazendo as próximas buscas serem muito mais rápidas.                        //
//                                                                                     //
// Essa versão faz a operação Find e Union em O(lg*(n)), que é na prática O(1).        //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "unionFind.h"
#include <stdlib.h> // malloc

// Aloca um UF na memória e inicializa com n conjuntos unitários
QUPH criaQUPH (int n) {
    QUPH novo = malloc (sizeof (struct quph));
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
int findQUPH (QUPH UF, int i) {
    // Sobe a árvore até a raiz
    while (i != UF->id[i]) {
        UF->id[i] = UF->id[UF->id[i]]; // Path Halving, reduz na metade a altura
        i = UF->id[i];
    }
    return i;
}

// Conecta os elementos i e j no UnionFind UF
void unionQUPH (QUPH UF, int i, int j) {
    i = findQUPH (UF, i);
    j = findQUPH (UF, j);
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
