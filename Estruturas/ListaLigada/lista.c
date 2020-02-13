#include "lista.h"

// Insere um elemento de tamanho sz no começo da lista
void insere (No *lista, void *elemento, size_t sz) {
    No novo = malloc (sizeof (struct no));
    novo->tamanho = sz;
    // novo->valor = elemento
    while (sz--) ((char *) novo->valor)[sz] = ((char *) elemento)[sz];
    novo->prox = *lista;
    *lista = novo;
}

// Insere um elemento de tamanho sz no final da lista
void insereFim (No *lista, void *elemento, size_t sz) {
    // cria o elemento
    No novo = malloc (sizeof (struct no));
    novo->tamanho = sz;
    while (sz--) ((char *) novo->valor)[sz] = ((char *) elemento)[sz];
    novo->prox = NULL;
    // insere na lista
    if (*lista == NULL) {
        *lista = novo;
        return;
    }
    No ultimo = *lista;
    while (ultimo->prox != NULL)
        ultimo = ultimo->prox;
    ultimo->prox = novo;
}

// Versão do insere que retorna um ponteiro para a nova lista
No insere (No lista, void *elemento, size_t sz) {
    No novo = malloc (sizeof (struct no));
    novo->tamanho = sz;
    // novo->valor = elemento
    while (sz--) ((char *) novo->valor)[sz] = ((char *) elemento)[sz];
    novo->prox = *lista;
    return novo;
}

// Recebe uma lista ordenada e insere o elemento mantendo a ordem estabelecida pela função compara
void insereOrdenado (No *lista, void *elemento, size_t sz, int (*compara)(void *, void *));

// Remove a primeira aparição do elemento na lista
void remove (No *lista, void *elemento, size_t sz);

// Busca o elemento na lista e retorna o nó que o elemento está ou NULL se ele não está
No busca (No lista, void *elemento, size_t sz);

// Verifica se a lista está vazia
bool estaVazia (No lista) {
    return lista == NULL;
}

// Limpa todos os nós da lista
void limpa (No *lista);

// Retorna a quantidade de elementos na lista
int tamanho (No lista) {
    int n = 0;
    while (lista != NULL) {
        n++;
        lista = lista->prox;
    }
    return n;
}