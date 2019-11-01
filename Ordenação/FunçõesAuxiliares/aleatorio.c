#include "../vetor.h"
#include <stdlib.h> // malloc() e rand()
#include <time.h> // timer para semente aleatorio

// Funções que geram coisas aleatórias

int intAleatorio (int min, int max) {
    double r = rand() / (double) RAND_MAX;
    return (r * (max - min) + min);
}

float floatAleatorio (float min, float max) {
    double r = rand() / (double) RAND_MAX;
    return (r * (max - min) + min);
}

double doubleAleatorio (double min, double max) {
    double r = rand() / (double) RAND_MAX;
    return (r * (max - min) + min);
}

vetor INTaleatorio (int n, int min, int max) {
    int vi;
    srand (time (NULL));
    vetor v = iniciaVetor (n, sizeof (int));
    for (int i = 0; i < n; i++) {
        vi = intAleatorio(min, max);
        atribui (v, i, sizeof (int), &vi);
    }
    return v;
}

vetor CHARaleatorio (int n, char min, char max) {
    char vi;
    srand (time (NULL));
    vetor v = iniciaVetor (n, sizeof (char));
    for (int i = 0; i < n; i++) {
        vi = intAleatorio(min, max);
        atribui (v, i, sizeof (char), &vi);
    }
    return v;
}

vetor FLOATaleatorio (int n, float min, float max) {
    float vi;
    srand (time (NULL));
    vetor v = iniciaVetor (n, sizeof (float));
    for (int i = 0; i < n; i++) {
        vi = floatAleatorio(min, max);
        atribui (v, i, sizeof (float), &vi);
    }
    return v;
}

vetor DOUBLEaleatorio (int n, double min, double max) {
    double vi;
    srand (time (NULL));
    vetor v = iniciaVetor (n, sizeof (double));
    for (int i = 0; i < n; i++) {
        vi = doubleAleatorio(min, max);
        atribui (v, i, sizeof (double), &vi);
    }
    return v;
}