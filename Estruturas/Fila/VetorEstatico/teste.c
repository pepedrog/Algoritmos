#include "fila.h"
#include <stdio.h>

// Programinha besta só pra testar a fila
// para compilar: gcc -o teste fila.c teste.c fila.h
int main () {
    char *inicio; // Variável pra guardar o topo da pilha, tem que lembrar de dar free
    Fila F = criaFila (10 * sizeof (char), 6);
    enfileira (F, "sera");
    enfileira (F, "que");
    enfileira (F, "vai");
    inicio = (char *) desenfileiraE(F);
    printf ("%s\n", inicio);
    free (inicio);
    enfileira (F, "funcionar");
    enfileira (F, "?");
    printf ("tamanho da fila: %d\n", tamanho (F));
    while (! estaVazia (F)) {
        inicio = (char *) desenfileiraE(F);
        printf ("%s\n", inicio);
        free (inicio);
    }
    limpa (F); // pra testar se limpa mesmo usar o valgrind
} 