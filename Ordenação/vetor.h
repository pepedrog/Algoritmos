// Esse ifndef previne que o conteúdo seja definido/incluido duas vezes
#ifndef VETOR_H
#define VETOR_H

#define TRUE 1
#define FALSE 0

// Nosso vetor será um ponteiro sem tipo
typedef void* vetor;
// size_t será o tamanho dos elementos do vetor
typedef unsigned long size_t;

typedef char bool;
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

// Copia conteudo de ori para dest
void copiaMemoria (char *dest, char *ori, size_t sz);

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

// Macro para facilitar a chamada de tipos específicos
#define ordenaTipo(v, n, tipo, algoritmo) algoritmo(v, n, sizeof(tipo), tipo##_compara)

// Funções de comparação dos tipos primitivos (implementei pra facilitar os testes)
int int_compara (const void *a, const void *b);
int char_compara (const void *a, const void *b);
int float_compara (const void *a, const void *b);
int double_compara (const void *a, const void *b);

bool estaOrdenado (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));

void selectionSort  (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));
void insertionSort  (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));
void bubbleSort     (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));
void cocktailSort   (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));
void mergeSort      (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));
void quickSort      (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));
void quickSortOtim1 (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));
void quickSortOtim2 (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));
void quickSortOtim3 (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));
void heapSort       (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));
void countingSort   (int *v, int n, int k);

#endif