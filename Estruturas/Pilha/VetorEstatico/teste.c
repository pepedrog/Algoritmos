#include <stdio.h>
#include "pilha.h"

// Pra compilar: gcc -Wall -o teste pilha.c teste.c pilha.h  

int main () {
    // Uma pilha de floats só pra testar
    Pilha P = criaPilha (sizeof (float), 10);
    float ini = 0.75;
    while (! estaCheia (P)) {
        empilha (P, (void *) &ini);
        ini *= 2;
    }
    desempilha (P);
    printf ("tamanho da pilha %d\n", tamanho (P)); // isso aqui tem que dar 9
    desempilha (P);
    empilha (P, &ini);
    desempilha (P);
    empilha (P, &ini);
    ini *= 2;
    empilha (P, &ini);
    float * topo;
    while (! estaVazia (P)) {
        topo = (float *) desempilhaE (P);
        printf ("%f\n", *topo);
        free (topo); // tem que limpar pq ele devolve uma cópia, não só um ponteiro
    }
    
    limpa (P); // Pra testar o limpa() usar o valgrind
}
