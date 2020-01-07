#include "pilha.h"

// Empilha (push) na pilha P um elemento de tamanho sz
void empilha (Pilha *P, void *elemento, size_t sz) {
    *P = empilhaP (*P, elemento, sz);
}

// Empilha (push) o elemento de tamanho sz e retorna a nova pilha
Pilha empilhaP (Pilha P, void *elemento, size_t sz) {
    // Cria um novo nó
    Pilha nova = malloc (sizeof (struct no));
    nova->tamanho = sz;
    nova->valor = malloc (sz);
    while (sz--)
        ((char *) nova->valor)[sz] = ((char *) elemento)[sz];
    nova->prox = P;
    return nova;
}

// Desempilha (pop) o elemento do topo
void desempilha (Pilha *P) {
    *P = desempilhaP (*P);
}

// Desempilha (pop) o elemento do topo e retorna a nova pilha
Pilha desempilhaP (Pilha P) {
    if (P == NULL) return NULL;
    Pilha aux = P->prox;
    free (P->valor);
    free (P);
    return aux;
}

// Desempilha (pop) o elemento do topo e retorna o elemento desempilhado
void *desempilhaE (Pilha *P) {
    void * topo_aux = topo (*P);
    desempilha (P);
    return topo_aux;
}

// Retorna uma cópia do elemento do topo de P
void *topo (Pilha P) {
    if (P == NULL) return NULL;
    void * copia = malloc (P->tamanho);
    for (int i = 0; i < P->tamanho; i++) 
        ((char *) copia)[i] = ((char *) P->valor)[i];
    return copia;
}

// Verifica se a pilha está vazia
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