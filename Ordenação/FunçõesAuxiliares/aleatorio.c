#include "../vetor.h"
#include <stdlib.h> // malloc() e rand()
#include <time.h> // clock (semente aleatorio)

typedef char byte;

vetor aleatorio (int n, size_t sz) {
    srand (time (NULL));
    int tamanho = sz * n;
    byte b;
    vetor v = malloc (tamanho);
    // Vai colocando bytes aleatorios até acabar
    for (int i = 0; i < tamanho; i++) {
        b = (byte) rand();
        atribui (v, i, 1, &b);
    }
    return v;
}


vetor INTaleatorio (int n) {
    return aleatorio (n, sizeof (int));
}

vetor CHARaleatorio (int n) {
    return aleatorio (n, sizeof (char));
}

vetor FLOATaleatorio (int n) {
    return aleatorio (n, sizeof (float));
}

vetor DOUBLEaleatorio (int n) {
    return aleatorio (n, sizeof (double));
}