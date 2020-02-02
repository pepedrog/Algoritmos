/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                                 Union Find                                          //
//                  Versão Weighted Quick Union pela altura                            //
//                                                                                     //
// Nessa implementação, é feito uma busca numa árvore de ids, até que o id do elemento //
// seja ele mesmo (raiz da árvore)                                                     //
// Dois elementos i e j estão conectados somente se esse processo de busca conduzir a  //
// a uma mesma raíz.                                                                   //
//                                                                                     //
// Essa versão faz a operação Find e Union em O(lg(n)).                                //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "unionFind.h"
#include <stdlib.h> // malloc

// Aloca um UF na memória e inicializa com n conjuntos unitários
HQU criaHQU (int n) {
    HQU novo = malloc (sizeof (struct hqu));
    novo->n = n;
    novo->id = malloc (n * sizeof (int));
    novo->h = malloc (n * sizeof (int));
    while (n--) {
        novo->id[n] = n;
        novo->h[n] = 1;
    }
    return novo;
}

// Devolve o identificador do conjunto do elemento i no Union Find UF
int findHQU (HQU UF, int i) {
    // Sobe a árvore até a raiz
    while (i != UF->id[i])
        i = UF->id[i];
    return i;
}

// Conecta os elementos i e j no UnionFind UF
void unionHQU (HQU UF, int i, int j) {
    i = findHQU (UF, i);
    j = findHQU (UF, j);
    if (i == j) return;
    // Conecta o menor no maior
    if (UF->h[i] > UF->h[j])
        UF->id[j] = i;
    else {
        UF->id[i] = j;
        // A altura só muda se as duas alturas forem iguais
        if (UF->h[i] == UF->h[j])
            UF->h[j]++;
    }
}
