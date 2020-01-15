
// Implementações do que está em fila.h (melhor documentado lá)

#include "fila.h"

// Macro pra facilitar o aceso a fila
#define F(i) (((char *) F->vetor) + (i) * F->tamanho)

// Aloca uma Fila na memória, 
// tamanho = tamanho dos elementos, max = tamanho da Fila
Fila criaFila (size_t tamanho, int max) {
    Fila F = malloc (sizeof (struct fila));
    F->vetor = malloc (tamanho * max);
    F->n = 0;
    F->ini = 0;
    F->max = max;
    F->tamanho = tamanho;
    return F;
}

// Enfileira uma cópia do elemento de tamanho F->tamanho na Fila F
// Se a Fila está cheia, não faz nada
void enfileira (Fila F, void *elemento) {
    if (estaCheia (F)) return;
    int fim = (F->ini + F->n)%F->max; //índice do último da fila
    // Copia o elemento no final da fila
    for (int i = 0; i < F->tamanho; i++)
        F(fim)[i] = ((char *) elemento)[i]; 
    F->n++;
}

// Desenfileira (pop) o topo de P
void desenfileira (Fila F) {
    F->ini = (F->ini + 1)%F->max;
    F->n--;
    // Não precisa limpar o elemento pq qdo enfileirar outra coisa vai sobrescrever
}

// Desenfileira o topo de P e retorna uma cópia do elemento desenfileirado
void *desenfileiraE (Fila F) {
    void * aux = inicio (F);
    desenfileira (F);
    return aux;
}

// Retorna uma cópia do elemento no começo da Fila
void *inicio (Fila F) {
    void *copia = malloc (F->tamanho);
    for (int i = 0; i < F->tamanho; i++)
        ((char *) copia)[i] = F(F->ini)[i];
    return copia;
}

// Verifica se a Fila está vazia
bool estaVazia (Fila F) {
    return F->n == 0;
}

// Verifica se a Fila está cheia
bool estaCheia (Fila F) {
    return F->n == F->max;
}

// Limpa a Fila da memória
void limpa (Fila F) {
    free (F->vetor);
    free (F);
}

// Retorna a quantidade de elementos na Fila
int tamanho (Fila F) {
    return F->n;
}