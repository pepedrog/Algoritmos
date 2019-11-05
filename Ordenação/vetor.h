
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

vetor INTaleatorio (int n, int min, int max);
vetor CHARaleatorio (int n, char min, char max);
vetor FLOATaleatorio (int n, float min, float max);
vetor DOUBLEaleatorio (int n, double min, double max);

/////////////////////////////////////////////////////
// 
// Funções que manipulam elementos do vetor
//
/////////////////////////////////////////////////////

// Aloca memória pro vetor
vetor iniciaVetor (int n, size_t sz);

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

/////////////////////////////////////////////////////
// 
// Funções dos diversos algoritmos de Ordenação
//
/////////////////////////////////////////////////////

// SelectionSort
void selectionSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));

void INTselectionSort (vetor v, int n);
void CHARselectionSort (vetor v, int n);
void FLOATselectionSort (vetor v, int n);
void DOUBLEselectionSort (vetor v, int n);

// InserionSort
void insertionSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));

void INTinsertionSort (vetor v, int n);
void CHARinsertionSort (vetor v, int n);
void FLOATinsertionSort (vetor v, int n);
void DOUBLEinsertionSort (vetor v, int n);

// BubbleSort
void bubbleSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));

void INTbubbleSort (vetor v, int n);
void CHARbubbleSort (vetor v, int n);
void FLOATbubbleSort (vetor v, int n);
void DOUBLEbubbleSort (vetor v, int n);

// CocktailSort
void cocktailSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));

void INTcocktailSort (vetor v, int n);
void CHARcocktailSort (vetor v, int n);
void FLOATcocktailSort (vetor v, int n);
void DOUBLEcocktailSort (vetor v, int n);
#endif