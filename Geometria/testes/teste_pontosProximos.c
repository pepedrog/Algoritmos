
// Teste para achar o par de pontos mais próximo
// compilar com 'make pontosProximos'
#include "../geometria.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
    int n = 15;
    ponto *P = malloc (n * sizeof (ponto));
    // sorteando n pontos num plano 10x10
    srand (1);
    for (int i = 0; i < n; i++)
        P[i] = novoPonto ((rand() / (float) RAND_MAX) * 10, (rand() / (float) RAND_MAX) * 10);

    par pertos = pontosProximos (P, n);
    printf ("O par de pontos mais próximo é (%.3f, %.3f) e (%.3f, %.3f) com dist^2 %.3f\n", 
            pertos.p1.x, pertos.p1.y, pertos.p2.x, pertos.p2.y, dist2 (pertos.p1, pertos.p2));
}