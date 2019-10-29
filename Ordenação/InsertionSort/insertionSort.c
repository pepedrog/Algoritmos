#include "../FunçõesAuxiliares/compara.h" // Funções de comparação pros tipos primitivos
#include "../vetor.h" // Definião do vetor e troca()
#include <stdlib.h> // malloc 

#define v(i) ((char *) v + (i) * sz)

void copiaMemoria (char *dest, char *ori, size_t sz);

// Ordena o vetor v com a ordem estabelecida pela função compara
void insertionSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {

    int i; // Índice que estamos inserindo
    int j; // Iterador da parte ordenada que procura o lugar da inserção
    void *guardai = malloc (sz); // Guarda o valor do v[i] pra por no lugar certo

    // Vai inserindo os elementos até inserir todos na parte ordenada
    for (i = 1; i < n; i++) {
        copiaMemoria (guardai, v(i), sz);
        j = i - 1;
        // Vai empurrando os elementos pra esquerda até chegar na posição do i
        while (j >= 0 && compara(v(j), guardai) > 0) {
            copia(v, j + 1, j, sz);
            j--;
        }
        // Coloca o i (que tá no guardai) no lugar dele
        copiaMemoria (v(j + 1), guardai, sz);
    }
}

void INTinsertionSort (vetor v, int n) {
    insertionSort (v, n, sizeof (int), INTcompara);
}

void FLOATinsertionSort (vetor v, int n) {
    insertionSort (v, n, sizeof (int), FLOATcompara);
}

void DOUBLEinsertionSort (vetor v, int n) {
    insertionSort (v, n, sizeof (int), DOUBLEcompara);
}

void CHARinsertionSort (vetor v, int n) {
    insertionSort (v, n, sizeof (int), CHARcompara);
}