
// Esse ifndef define previne que o conteúdo seja definido/incluido duas vezes
#ifndef VETOR_H
#define VETOR_H

// Nosso vetor será um ponteiro sem tipo
typedef void* vetor;
// size_t será o tamanho
// void STRINGgetVetor (vetor v, int n); dos elementos do vetor
typedef unsigned long size_t;


/////////////////////////////////////////////////////
//
// Funções que lêem o vetor da entrada padrão
//
/////////////////////////////////////////////////////

void INTgetVetor (vetor v, int n);
void CHARgetVetor (vetor v, int n);
void FLOATgetVetor (vetor v, int n);
void DOUBLEgetVetor (vetor v, int n);

/////////////////////////////////////////////////////
// 
// Funções que printam o vetor na saida padrão
//
/////////////////////////////////////////////////////

void INTprintaVetor (vetor v, int n);
void CHARprintaVetor (vetor v, int n);
void FLOATprintaVetor (vetor v, int n);
void DOUBLEprintaVetor (vetor v, int n);

/////////////////////////////////////////////////////
// 
// Geradores de vetores 'aleatórios'
//
/////////////////////////////////////////////////////

vetor INTaleatorio (int n);
vetor CHARaleatorio (int n);
vetor FLOATaleatorio (int n);
vetor DOUBLEaleatorio (int n);
vetor aleatorio (int n, size_t sz);

/////////////////////////////////////////////////////
// 
// Funções que manipulam elementos do vetor
//
/////////////////////////////////////////////////////

// Faz v[i] = conteudo
void atribui (vetor v, int i, size_t sz, void *conteudo);

// Troca o conteúdo de i com o conteúdo de j
void troca (vetor v, int i, int j, size_t sz);

// Copia o conteúdo de v[ori] para v[dest]
void copia (vetor v, int dest, int src, size_t sz);

// Função que copia o vetor ori no vetor dest
void copiaVetor(vetor dest, vetor ori, int n, size_t sz);

// Função que devolve uma cópia/clone do vetor v
vetor clonaVetor (vetor v, int n, size_t sz);

#endif