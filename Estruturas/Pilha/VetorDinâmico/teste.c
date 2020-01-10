#include <stdio.h>
#include "pilha.h"

// Pra compilar: gcc -Wall -o teste pilha.c teste.c pilha.h  

// Pra facilitar a empilhação
#define emp(x) e = (x), empilha(&P, &e), printaTopo

#define printaTopo printf("topo: %d\n", *((int *)(topo(P))))

int main () {
    // Uma pilha de ints só pra testar
    Pilha P = criaPilha (sizeof (int));
    // Primeiras empilhadas e desempilhadas antes da pilha dar resize
    int e;
    emp(3);
    emp(1);
    emp(4);
    desempilha (&P);
    emp(1);

    printf ("tamanho da pilha %d\n", tamanho (P)); // isso aqui tem que dar 4
    desempilha (&P);
    emp(4);
    emp(1);
    printf ("capacidade da pilha: %d\n", P->tamanho);
    emp(5); // Aqui a pilha deve dar resize
    printf ("capacidade da pilha: %d\n", P->tamanho);
    emp(9);
    desempilha (&P);
    emp(2);
    emp(5);
    emp(8);
    printf ("capacidade da pilha: %d\n", P->tamanho);
    emp(7); // Outro resize
    printf ("capacidade da pilha: %d\n", P->tamanho);
    emp(7);
    emp(9);
    printf ("tamanho da pilha %d\n", tamanho (P));
    int *topo;
    while (! estaVazia (P)) {
        topo = (int *) desempilhaE (&P);
        printf ("%d\n", *topo);
        free (topo); // tem que limpar pq ele devolve uma cópia, não só um ponteiro
    }
    
    limpa (P); // Pra testar o limpa() usar o valgrind
}
