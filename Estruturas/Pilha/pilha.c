#include "pilha.h"

// Empilha (push) na pilha P um elemento de tamanho sz
void empilha (Pilha P, void *elemento, size_t sz) {
    // Cria um novo nó
    struct no novo;
    // Copia o elemento pro novo (faz um strcpy)
    novo.valor = malloc(sz);
    while (sz--)
        ((char *) novo.valor)[sz] = ((char *) elemento)[sz];
    // Coloca o topo da pilha como próximo 
    novo.prox = P;
    *P = novo;
}

// Desempilha (pop) e retorna o elemento do topo de P
void *desempilha (Pilha P) {
    if (P == NULL) printf ("Pilha já está vazia\n");
    void *topo = P->valor;
    P = P->prox;
    return topo;
}

// Verifica de a pilha está vazia
bool estaVazia (Pilha P) {
    return P == NULL;
}

// Limpa todos os nós da pilha
void limpa (Pilha P) {
    free (P->valor);
    limpa (P->prox);
    free (P);
}

// Retorna a quantidade de elementos na pilha (tempo linear)
int tamanho (Pilha P) {
    int tam = 0;
    Pilha aux = P;
    while (aux != NULL) {
        aux = aux->prox;
        tam++;
    }
    return tam;
}
