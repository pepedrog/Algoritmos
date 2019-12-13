#include "../vetor.h"

#define v(i) ((char *) v + (i) * sz)

bool estaOrdenado (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    for (int i = 1; i < n; i++) 
        if (compara (v(i - 1), v(i)) > 0) return FALSE;
    return TRUE;
}
