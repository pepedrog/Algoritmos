#include "../vetor.h"
#include "compara.h"

#define v(i) ((char *) v + (i) * sz)

bool estaOrdenado (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    for (int i = 1; i < n; i++) 
        if (compara (v(i - 1), v(i)) > 0) return FALSE;
    return TRUE;
}

bool INTestaOrdenado (vetor v, int n) {
    return estaOrdenado (v, n, sizeof (int), INTcompara);
}
bool CHARestaOrdenado (vetor v, int n) {
    return estaOrdenado (v, n, sizeof (char), CHARcompara);
}
bool FLOATestaOrdenado (vetor v, int n) {
    return estaOrdenado (v, n, sizeof (float), FLOATcompara);
}
bool DOUBLEestaOrdenado (vetor v, int n) {
    return estaOrdenado (v, n, sizeof (double), DOUBLEcompara);
}