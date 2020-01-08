#include "pilha.h"
#include <stdio.h>

// Programinha besta só pra testar a pilha
// para compilar: $gcc -o teste pilha.c teste.c pilha.h
int main () {
    Pilha P = NULL;
    empilha (&P, "?", 2);
    empilha (&P, "sera", 5);
    printf ("%s\n", (char *) desempilhaE(&P));
    empilha (&P, "funcionar", 10);
    empilha (&P, "vai", 4);
    empilha (&P, "que", 4);
    printf ("tamanho da pilha: %d\n", tamanho (P));
    while (! estaVazia (P))
        printf ("%s\n", (char *) desempilhaE(&P));
} 