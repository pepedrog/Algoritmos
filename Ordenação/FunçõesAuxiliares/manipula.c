#include "../vetor.h"
#include <stdlib.h>

void copiaMemoria (char *dest, char *ori, size_t sz) {
    for (size_t t = 0; t < sz; t++) *(dest + t) = *(ori + t);
}

void copia (vetor v, int dest, int ori, size_t sz) {
    copiaMemoria ((char *) v + dest * sz, (char *) v + ori * sz, sz);
}

void troca (vetor v, int i, int j, size_t sz) {
    char *aux = malloc (sz);
    copiaMemoria (aux, (char *) v + i * sz, sz);
    copiaMemoria ((char *) v + i * sz, (char *) v + j * sz, sz);
    copiaMemoria ((char *) v + j * sz, aux, sz);
}