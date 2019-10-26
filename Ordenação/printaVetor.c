///////////////////////////////////////////////////////////////////////////
//
// Funções que lêem vetores na entrada padrão
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
// Recomendo não compilar com -Wpedantic pois ignoramos o retorno do printf
// 
///////////////////////////////////////////////////////////////////////////

#include "vetor.h" // definição de vetor
#include <stdio.h> // printf()

// Le n inteiros da entrada padrão e guarda no vetor v
void INTgetVetor (vetor v, int n) {
    for (int i = 0; i < n; i++)
        scanf ("%d", (int *) ((char *) v + i * sizeof (int)));
}

// Le n floats da entrada padrão e guarda no vetor v
void FLOATgetVetor (vetor v, int n) {
    for (int i = 0; i < n; i++)
        scanf ("%f", (float *) ((char *) v + i * sizeof (float)));
}

// Le n doubles da entrada padrão e guarda no vetor v
void DOUBLEgetVetor (vetor v, int n) {
    for (int i = 0; i < n; i++)
        scanf ("%lf", (double *) ((char *) v + i * sizeof (double)));
}

// Le n chars da entrada padrão e guarda no vetor v
void CHARgetVetor (vetor v, int n) {
    for (int i = 0; i < n; i++)
        scanf ("%c", (char *) v + i);
}#include <stdio.h>
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