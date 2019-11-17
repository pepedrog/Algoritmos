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

// Funções para conferir se o vetor está ordenado
bool estaOrdenado (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));

bool INTestaOrdenado (vetor v, int n);
bool CHARestaOrdenado (vetor v, int n);
bool FLOATestaOrdenado (vetor v, int n);
bool DOUBLEestaOrdenado (vetor v, int n);

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

// MergeSort
void mergeSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));

void INTmergeSort (vetor v, int n);
void CHARmergeSort (vetor v, int n);
void FLOATmergeSort (vetor v, int n);
void DOUBLEmergeSort (vetor v, int n);

// QuickSort
void quickSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));

void INTquickSort (vetor v, int n);
void CHARquickSort (vetor v, int n);
void FLOATquickSort (vetor v, int n);
void DOUBLEquickSort (vetor v, int n);

// HeapSort
void heapSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));

void INTheapSort (vetor v, int n);
void CHARheapSort (vetor v, int n);
void FLOATheapSort (vetor v, int n);
void DOUBLEheapSort (vetor v, int n);

#endif