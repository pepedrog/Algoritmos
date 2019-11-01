#include <stdio.h> // scanf
#include "../vetor.h"

int main (void) {
    int n;
    scanf ("%d", &n);
    //vetor v = iniciaVetor (n, sizeof (int));
    vetor v = INTaleatorio (n, 0, 100);

    //INTgetVetor (v, n);
    INTprintaVetor (v, n);

    vetor ordena = clonaVetor (v, n, sizeof (int));
    INTselectionSort (ordena, n);
    INTprintaVetor (ordena, n);

    copiaVetor (ordena, v, n, sizeof (int));
    INTinsertionSort (ordena, n);
    INTprintaVetor (ordena, n);
}