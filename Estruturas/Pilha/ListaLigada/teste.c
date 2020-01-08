#include "pilha.h"
#include <stdio.h>

// Programinha besta só pra testar a pilha
// para compilar: gcc -o teste pilha.c teste.c pilha.h
int main () {
    char *topo; // Variável pra guardar o topo da pilha, tem que lembrar de dar free
    Pilha P = NULL;
    empilha (&P, "?", 2);
    empilha (&P, "sera", 5);
    topo = (char *) desempilhaE(&P);
    printf ("%s\n", topo);
    free (topo);
    empilha (&P, "funcionar", 10);
    empilha (&P, "vai", 4);
    empilha (&P, "que", 4);
    printf ("tamanho da pilha: %d\n", tamanho (P));
    while (! estaVazia (P)) {
        topo = (char *) desempilhaE(&P);
        printf ("%s\n", topo);
        free (topo);
    }
    limpa (&P); // pra testar se limpa mesmo usar o valgrind
} 