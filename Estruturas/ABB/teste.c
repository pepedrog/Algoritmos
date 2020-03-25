// Teste para uma ABB, as chaves serao inteiras e os valores strings

#include "abb.h"
#include <stdio.h>

// Função de copmparação entre inteiros
int compara (const void * a, const void * b) {
    return (*((int *) a) - *((int *) b));
}

int main () {
    int chave;
    char *valor;
    Abb arvore = ABBnovaAbb (*compara);

    // O 4 vai ser nossa raiz
    chave = 4;
    valor = "quarto";
    ABBinsere (arvore, (void *) &chave, sizeof (int), (void *) &valor, sizeof (*valor));

    chave = 2;
    valor = "segundo";
    ABBinsere (arvore, (void *) &chave, sizeof (int), (void *) &valor, sizeof (*valor));

    chave = 3;
    valor = "terceiro";
    ABBinsere (arvore, (void *) &chave, sizeof (int), (void *) &valor, sizeof (*valor));

    chave = 1;
    valor = "primeiro";
    ABBinsere (arvore, (void *) &chave, sizeof (int), (void *) &valor, sizeof (*valor));

    chave = 5;
    valor = "quinto";
    ABBinsere (arvore, (void *) &chave, sizeof (int), (void *) &valor, sizeof (*valor));

    /* A arvore ficou
                4
        2-------|--------5
    1---|---3

    altura = 2
    nos = 5 */

    // Testes 1
    No buscado;
    for (int i = 0; i < 7; i+=2) {
        chave = i;
        buscado = ABBbusca (arvore, (void *) &chave);
        printf ("%d ", i);
        if (buscado == NULL) printf ("não está na árvore\n");
        else printf ("está na árvore \n");
    }
    printf ("altura = %d\nnos = %d\n", ABBaltura (arvore), ABBnos (arvore));
}