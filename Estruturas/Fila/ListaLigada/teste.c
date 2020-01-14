#include "fila.h"
#include <stdio.h>

// Programinha besta só pra testar a pilha
// para compilar: gcc -o teste pilha.c teste.c pilha.h
int main () {
    char *inicio; // Variável pra guardar o topo da pilha, tem que lembrar de dar free
    Fila F = iniciaFila();
    enfileira (F, "sera", 5);
    enfileira (F, "que", 4);
    enfileira (F, "vai", 4);
    inicio = (char *) desenfileiraE(F);
    printf ("%s\n", inicio);
    free (inicio);
    enfileira (F, "funcionar", 10);
    enfileira (F, "?", 2);
    printf ("tamanho da fila: %d\n", tamanho (F));
    while (! estaVazia (F)) {
        inicio = (char *) desenfileiraE(F);
        printf ("%s\n", inicio);
        free (inicio);
    }
    limpa (F); // pra testar se limpa mesmo usar o valgrind
} 