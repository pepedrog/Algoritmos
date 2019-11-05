#include "../vetor.h"
#include <stdlib.h>

// Macros pra facilitar o acesso aos vetores
#define v(i) ((char *) v + (i) * sz)
#define dest(i) ((char *) dest + (i) * sz)
#define ori(i) ((char *) ori + (i) * sz)

// Função que aloca um vetor na memória
vetor iniciaVetor (int n, size_t sz) {
    vetor v = malloc (n * sz);
    return v;
}

// Função que copia o conteúdo de ori em dest
// Recebe dois ponteiros e memória (está char* ao invés de void* para evitar warnings)
// Equivalente ao memcpy() do string.h
void copiaMemoria (char *dest, char *ori, size_t sz) {
    while (sz--) *(dest + sz) = *(ori + sz);
}

// Faz v[i] = conteudo
void atribui (vetor v, int i, size_t sz, void *conteudo) {
    copiaMemoria (v(i), (char *) conteudo, sz);
}

// Copia os n primeiros elementos do vetor ori no vetor dest
void copiaVetor (vetor dest, vetor ori, int n, size_t sz) {
    for (int i = 0; i < n; i++) 
        copiaMemoria (dest(i), ori(i), sz);
}

// Função que devolve uma cópia do vetor v
vetor clonaVetor (vetor v, int n, size_t sz) {
    vetor novo = malloc (n * sz);
    copiaVetor (novo, v, n, sz);
    return novo;
}

// Função que copia o conteúdo de v[ori] em v[dest]
void copia (vetor v, int dest, int ori, size_t sz) {
    copiaMemoria ((char *) v + dest * sz, (char *) v + ori * sz, sz);
}

// Função que troca os conteúdos dos índices i e j do vetor
void troca (vetor v, int i, int j, size_t sz) {
    char *aux = malloc (sz);
    copiaMemoria (aux, v(i), sz);
    copiaMemoria (v(i), v(j), sz);
    copiaMemoria (v(j), aux, sz);
    free (aux);
}