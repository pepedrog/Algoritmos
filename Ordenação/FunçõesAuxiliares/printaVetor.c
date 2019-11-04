///////////////////////////////////////////////////////////////////////////
//
// Funções que printam vetores na saída padrão
//
// Como os vetores são ponteiros void, é preciso fazer um malabarismo
// de conversão de tipos
//
// O compilador não gosta de acessar um vetor void, então convertemos
// ele para um vetor char (que tem o mesmo tamanho, 1 byte)
//
// Depois, para acessar v[i] temos que fazer v + i * tamanho_do_elemento
// E converter isso para o tipo especificado no nome da função
// 
///////////////////////////////////////////////////////////////////////////

#include "../vetor.h" // definição de vetor
#include <stdio.h> // printf()

// Printa n inteiros do vetor v na saída
void INTprintaVetor (vetor v, int n) {
    for (int i = 0; i < n - 1; i++)
        printf ("%d ", *((int *) ((char *) v + i * sizeof (int))));
    printf ("%d\n", *((int *) ((char *) v + (n - 1) * sizeof (int))));
}

// Printa n floats do vetor v na saída
void FLOATprintaVetor (vetor v, int n) {
    for (int i = 0; i < n; i++)
        printf ("%f ", *((float *) ((char *) v + i * sizeof (float))));
    printf ("%f\n", *((float *) ((char *) v + (n - 1) * sizeof (float))));
}

// Printa n doubles do vetor v na saída
void DOUBLEprintaVetor (vetor v, int n) {
    for (int i = 0; i < n; i++)
        printf ("%lf ", *((double *) ((char *) v + i * sizeof (double))));
    printf ("%lf\n", *((double *) ((char *) v + (n - 1) * sizeof (double))));
}

// Printa n chars do vetor v na saída
void CHARprintaVetor (vetor v, int n) {
    for (int i = 0; i < n; i++)
        printf ("%c ", *((char *) v + i));
    printf ("%c\n", *((char *) v + n - 1));
}
/*
void STRINGprintaVetor (vetor v, int n);*/