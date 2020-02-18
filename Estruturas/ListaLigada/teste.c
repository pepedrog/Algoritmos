#include <stdio.h>
#include "lista.h"

int main () {
    No lista = NULL;
    int novo = 10;
    // testa inserção
    while (novo <= 100) {
        insere (&lista, (void *) &novo, sizeof (int));
        novo += 15;
    }
    printf ("inseri %d elementos\n", tamanho (lista));

    // testa busca
    int procura = 5;
    while (procura <= 100) {
        if (busca (lista, (void *) &procura, sizeof (int)) != NULL)
            printf ("encontrei %d\n", procura);
        else printf ("Não encontrei %d\n", procura);
        procura += 10;
    }

    // testa remove
    procura = 25;
    removeL (&lista, (void *) &procura, sizeof (int));
    if (busca (lista, (void *) &procura, sizeof (int)) != NULL)
            printf ("não removi o 25\n");
    else printf ("Removi o 25\n");

    limpa (&lista);
}