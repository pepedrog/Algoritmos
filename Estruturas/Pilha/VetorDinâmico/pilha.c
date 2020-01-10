
// Implementações do que está em pilha.h (melhor documentado lá)

#include "pilha.h"
#include <string.h>

// Macro pra facilitar o aceso a pilha
#define P(i) (((char *) P->vetor) + (i) * P->tam_elemento)

// Tamanho que a pilha é iniciada (potências de 2 são legais)
#define tamanhoInicial 4

// Copia a pilha P com um vetor com tamanho novo_tamanho
void redimensiona (Pilha P, int novo_tamanho) {
    P->tamanho = novo_tamanho;
    char *vetor = malloc (novo_tamanho * P->tam_elemento);
    for (int i = 0; i < P->topo * P->tam_elemento; i++)
            vetor[i] = ((char *) P->vetor)[i];
    free (P->vetor);
    P->vetor = (void *) vetor;
}

// Aloca uma pilha na memória
Pilha criaPilha (size_t tam_elemento) {
    Pilha P = malloc (sizeof (struct pilha));
    P->vetor = malloc (tam_elemento * tamanhoInicial);
    P->topo = 0;
    P->tam_elemento = tam_elemento;
    P->tamanho = tamanhoInicial;
    return P;
}

// Empilha uma cópia do elemento de tamanho P->tamanho na pilha P
// Se a pilha está cheia, não faz nada
void empilha (Pilha P, void *elemento) {
    // Se a pilha ta cheia, dobra ela de tamanho
    if (P->topo == P->tamanho) redimensiona (P, 2 * P->tamanho);
    // Copia o elemento no topo
    for (int i = 0; i < P->tam_elemento; i++)
        // P->vetor[topo][i] = elemento[i]
        P(P->topo)[i] = ((char *) elemento)[i];
    P->topo++;
}

// Desempilha (pop) o topo de P
void desempilha (Pilha P) {
    P->topo--;
    // Se a pilha tiver muito vazia (25%) diminui o tamanho
    if (P->tamanho > tamanhoInicial && P->topo < P->tamanho / 4) redimensiona (P, P->tamanho / 2);
}

// Desempilha o topo de P e retorna uma cópia do elemento desempilhado
void *desempilhaE (Pilha P) {
    void * topo_aux = topo (P);
    desempilha (P);
    return topo_aux;
}

// Retorna uma cópia do topo da pilha
void *topo (Pilha P) {
    void *copia = malloc (P->tam_elemento);
    for (int i = 0; i < P->tam_elemento; i++)
        ((char *) copia)[i] = P(P->topo - 1)[i];
    return copia;
}

// Verifica se a pilha está vazia
bool estaVazia (Pilha P) {
    return P->topo == 0;
}

// Limpa a pilha da memória
void limpa (Pilha P) {
    free (P->vetor);
    free (P);
}

// Retorna a quantidade de elementos na pilha
int tamanho (Pilha P) {
    return P->topo;
}