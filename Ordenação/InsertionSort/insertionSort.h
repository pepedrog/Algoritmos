#include "../vetor.h"

// Ordena o vetor v com a ordem estabelecida pela função compara
void insertionSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));

void INTinsertionSort (vetor v, int n);

void FLOATinsertionSort (vetor v, int n);

void DOUBLEinsertionSort (vetor v, int n);

void CHARinsertionSort (vetor v, int n);