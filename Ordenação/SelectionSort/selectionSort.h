#include "../vetor.h"

// Ordena o vetor v com a ordem estabelecida pela função compara
void selectionSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *));

void INTselectionSort (vetor v, int n);

void FLOATselectionSort (vetor v, int n);

void DOUBLEselectionSort (vetor v, int n);

void CHARselectionSort (vetor v, int n);