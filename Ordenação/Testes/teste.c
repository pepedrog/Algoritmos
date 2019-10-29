#include <stdlib.h> // malloc
#include <stdio.h> // scanf
#include "../vetor.h"
#include "../SelectionSort/selectionSort.h"
#include "../InsertionSort/insertionSort.h"

int main (void) {
    int n;
    if (!scanf ("%d", &n)) printf("ERRO: leitura incorreta do tamanho do vetor\n");
    // vetor v = malloc (n * sizeof (int));
    vetor v =   INTaleatorio (n);


    //INTgetVetor (v, n);
    INTprintaVetor (v, n);

    vetor ordena = clonaVetor (v, n, sizeof (int));
    INTselectionSort (ordena, n);
    INTprintaVetor (ordena, n);

    copiaVetor (ordena, v, n, sizeof (int));
    INTinsertionSort (ordena, n);
    INTprintaVetor (ordena, n);

}