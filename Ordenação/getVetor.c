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
// Recomendo não compilar com -Wpedantic pois ignoramos o retorno do scanf
// 
///////////////////////////////////////////////////////////////////////////

#include "vetor.h" // definição de vetor
#include <stdio.h> // scanf()

// Printa n inteiros da saída padrão e guarda no vetor v
void INTgetVetor (vetor v, int n) {
    for (int i = 0; i < n; i++)
        scanf ("%d", (int *) ((char *) v + i * sizeof (int)));
}

// Printa n floats da saída padrão e guarda no vetor v
void FLOATgetVetor (vetor v, int n) {
    for (int i = 0; i < n; i++)
        scanf ("%f", (float *) ((char *) v + i * sizeof (float)));
}

// Printa n doubles da saída padrão e guarda no vetor v
void DOUBLEgetVetor (vetor v, int n) {
    for (int i = 0; i < n; i++)
        scanf ("%lf", (double *) ((char *) v + i * sizeof (double)));
}

// Printa n chars da saída padrão e guarda no vetor v
void CHARgetVetor (vetor v, int n) {
    for (int i = 0; i < n; i++)
        scanf ("%c", (char *) v + i);
}
/*
void STRINGgetVetor (vetor v, int n);*/