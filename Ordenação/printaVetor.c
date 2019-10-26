#include <stdio.h>
#include "vetor.h"

void INTprintaVetor (vetor v, int n) {
    for (int i = 0; i < n; i++)
        printf ("%d\t", *((int *) (((char *) v) + i * sizeof (int))));
    puts ("\n");
}

void FLOATprintaVetor (vetor v, int n) {
    for (int i = 0; i < n; i++)
        printf ("%f\t", *((float *) (((char *) v) + i * sizeof (float))));
    puts ("\n");
}

void DOUBLEprintaVetor (vetor v, int n) {
    for (int i = 0; i < n; i++)
        printf ("%lf\t", *((double *) (((char *) v) + i * sizeof (double))));
    puts ("\n");
}

void CHARprintaVetor (vetor v, int n) {
    for (int i = 0; i < n; i++) printf ("%c\t", *((char *) v + i));
    puts ("\n");
}
/*
void STRINGprintaVetor (vetor v, int n);*/