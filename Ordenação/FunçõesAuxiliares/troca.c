#include "vetor.h"
#include <string.h>
#include <stdlib.h>
/*
void copia (char *dest, char *ori, size_t sz) {
    char aux;
    for (int i = )
}
*/
void troca (vetor v, int i, int j, size_t sz) {
    char *aux = malloc (sz);
    memcpy (aux, (char *) v + i * sz, sz);
    memcpy ((char *) v + i * sz, (char *) v + j * sz, sz);
    memcpy ((char *) v + j * sz, aux, sz);
}