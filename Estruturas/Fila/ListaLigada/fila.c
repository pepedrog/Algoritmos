#include "fila.h"

// Aloca uma fila vazia na memória
Fila iniciaFila () {
    Fila nova = malloc (sizeof (struct fila));
    nova->n = 0;
    nova->ultimo = nova->primeiro = NULL;
    return nova;
}

// Enfileira (push) o elemento de tamanho sz
void enfileira (Fila F, void *elemento, size_t sz) {
    // Cria um novo nó pro elemento
    struct no *novo = malloc (sizeof (struct no));
    novo->tamanho = sz;
    novo->valor = malloc (sz);
    while (sz--)
        ((char *) novo->valor)[sz] = ((char *) elemento)[sz];
    novo->prox = NULL;
    // Coloca o nó no final
    if (estaVazia (F))
        F->ultimo = F->primeiro = novo;
    else {
        F->ultimo->prox = novo;
        F->ultimo = novo;
    }
    F->n++;
}

// Desenfileira (pop) o elemento do topo
void desenfileira (Fila F) {
    if (estaVazia (F)) return;
    struct no *aux = F->primeiro;
    F->primeiro = F->primeiro->prox;
    F->n--;
    if (estaVazia (F)) F->ultimo = NULL;
    free (aux->valor);
    free (aux);
}

// Desenfileira (pop) o elemento do topo e retorna o elemento desenfileirado
void *desenfileiraE (Fila F) {
    void * topo_aux = inicio (F);
    desenfileira (F);
    return topo_aux;
}

// Retorna uma cópia do elemento do topo de P
void *inicio (Fila F) {
    if (F->primeiro == NULL) return NULL;
    void * copia = malloc (F->primeiro->tamanho);
    for (int i = 0; i < F->primeiro->tamanho; i++) 
        ((char *) copia)[i] = ((char *) F->primeiro->valor)[i];
    return copia;
}

// Verifica se a Fila está vazia
bool estaVazia (Fila F) {
    return F->n == 0;
}

// Limpa todos os nós da Fila
void limpa (Fila F) {
    while (! estaVazia (F))
        desenfileira (F);
    free (F);
}

// Retorna a quantidade de elementos na fila
int tamanho (Fila F) {
    return F->n;
}
