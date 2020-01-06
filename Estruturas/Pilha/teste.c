#include "pilha.h"
#include <stdio.h>

int main () {
    Pilha P;
    void * elemento = malloc(5 * sizeof(char));
    elemento = "sera";
    empilha (P, elemento, 5 * sizeof(char));
    printf ("%s\n", (char *) desempilha(P));
} 