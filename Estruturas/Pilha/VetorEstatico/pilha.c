
// Implementações do que está em pilha.h (melhor documentado lá)

#include "pilha.h"

// Macro pra facilitar o aceso a pilha
#define P(i) (((char *) P->vetor) + (i) * P->tamanho)

// Aloca uma pilha na memória, 
// tamanho = tamanho dos elementos, max = tamanho da pilha
Pilha criaPilha (size_t tamanho, int max) {
    Pilha P = malloc (sizeof (struct pilha));
    P->vetor = malloc (tamanho * max);
    P->topo = 0;
    P->max = max;
    P->tamanho = tamanho;
    return P;
}

// Empilha uma cópia do elemento de tamanho P->tamanho na pilha P
// Se a pilha está cheia, não faz nada
void empilha (Pilha P, void *elemento) {
    if (estaCheia (P)) return;
    // Copia o elemento no topo
    for (int i = 0; i < P->tamanho; i++)
        P(P->topo)[i] = ((char *) elemento)[i]; 
    P->topo++;
}

// Desempilha (pop) o topo de P
void desempilha (Pilha P) {
    P->topo--;
    // Não precisa limpar o topo pq qdo empilhar outra coisa vai sobrescrever
}

// Desempilha o topo de P e retorna uma cópia do elemento desempilhado
void *desempilhaE (Pilha P) {
    void * topo_aux = topo (P);
    desempilha (P);
    return topo_aux;
}

// Retorna uma cópia do topo da pilha
void *topo (Pilha P) {
    void *copia = malloc (P->tamanho);
    for (int i = 0; i < P->tamanho; i++)
        ((char *) copia)[i] = P(P->topo - 1)[i];
    return copia;
}

// Verifica se a pilha está vazia
bool estaVazia (Pilha P) {
    return P->topo == 0;
}

// Verifica se a pilha está cheia
bool estaCheia (Pilha P) {
    return P->topo == P->max;
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