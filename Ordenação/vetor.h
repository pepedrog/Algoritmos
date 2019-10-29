
// Esse define previne que os typedefs sejam definidos duas vezes
#ifndef VETOR_H
#define VETOR_H

// Nosso vetor será um ponteiro sem tipo
typedef void* vetor;
// size_t será o tamanho dos elementos do vetor
typedef unsigned long size_t;

#endif

/////////////////////////////////////////////////////
//
// Funções que lêem o vetor da entrada padrão
//
/////////////////////////////////////////////////////

void INTgetVetor (vetor v, int n);

void FLOATgetVetor (vetor v, int n);

void DOUBLEgetVetor (vetor v, int n);

void CHARgetVetor (vetor v, int n);

// void STRINGgetVetor (vetor v, int n);

/////////////////////////////////////////////////////
// 
// Funções que printam o vetor na saida padrão
//
/////////////////////////////////////////////////////

void INTprintaVetor (vetor v, int n);

void FLOATprintaVetor (vetor v, int n);

void DOUBLEprintaVetor (vetor v, int n);

void CHARprintaVetor (vetor v, int n);

// void STRINGprintaVetor (vetor v, int n);

/////////////////////////////////////////////////////
// 
// Funções que manipulam elementos do vetor
//
/////////////////////////////////////////////////////

// Troca o conteúdo de i com o conteúdo de j
void troca (vetor v, int i, int j, size_t sz);

// Copia o conteúdo de ori para dest (memcpy do string.h)
void copia (vetor v, int dest, int src, size_t sz)