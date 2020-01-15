// Implementações do que está em fila.h (melhor documentado lá)

#include "fila.h"
#include <string.h>

// Macro pra facilitar o aceso ao vetor da fila
#define F(i) (((char *) F->vetor) + (i) * F->tam_elemento)

// Tamanho que a fila é iniciada (potências de 2 são legais)
#define tamanhoInicial 4

// Copia a fila F com um vetor com tamanho novo_tamanho
void redimensiona (Fila F, int novo_tamanho) {
    F->tamanho = novo_tamanho;
    char *vetor = malloc (novo_tamanho * F->tam_elemento);
    for (int i = F->ini; i < F->fim * F->tam_elemento; i++)
            vetor[i] = ((char *) F->vetor)[i];
    free (F->vetor);
    F->vetor = (void *) vetor;
}

// Aloca uma fila na memória
Fila criaFila (size_t tam_elemento) {
    Fila F = malloc (sizeof (struct fila));
    F->vetor = malloc (tam_elemento * tamanhoInicial);
    F->ini = 0;
    F->fim = 0;
    F->tam_elemento = tam_elemento;
    F->tamanho = tamanhoInicial;
    return F;
}

// Enfileira (enqueue) uma cópia do elemento de tamanho F->tam_elemento na fila F
void enfileira (Fila F, void *elemento) {
    // Se a fila ta "cheia", dobra ela de tamanho
    // Na verdade, ela pode não estar cheia, pois pode ter sido desenfileirada já,
    // Mas se fossemos tentar adicionar nos espaços livres seria muito complicante
    if (F->fim == F->tamanho) redimensiona (F, 2 * F->tamanho);
    // Copia o elemento no topo
    for (int i = 0; i < F->tam_elemento; i++)
        // P->vetor[topo][i] = elemento[i]
        F(F->fim)[i] = ((char *) elemento)[i];
    F->fim++;
}

// Desenfileira (dequeue) o elemento no começo da F
void desenfileira (Fila F) {
    F->ini++;
}

// Desenfileira o começo de F e retorna uma cópia do elemento desenfileirado
void *desenfileiraE (Fila F) {
    void * aux = inicio (F);
    desenfileira (F);
    return aux;
}

// Retorna uma cópia do elemento do começo da fila
void *inicio (Fila F) {
    void *copia = malloc (F->tam_elemento);
    for (int i = 0; i < F->tam_elemento; i++)
        ((char *) copia)[i] = F(F->ini)[i];
    return copia;
}

// Verifica se a fila está vazia
bool estaVazia (Fila F) {
    return F->ini == F->fim;
}

// Limpa a fila da memória
void limpa (Fila F) {
    free (F->vetor);
    free (F);
}

// Retorna a quantidade de elementos na fila
int tamanho (Fila F) {
    return F->fim - F->ini;
}