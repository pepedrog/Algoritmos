/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                                   Shell Sort                                        //
//                                                                                     //
// Algoritmo de ordenação baseado na seguinte ideia:                                   //
// - O vetor será vários vetores ordenados intercalados                                //
// - Cada vetor está intercalado por k elementos (0, h, hk; 1, h + 1, 2h + 1; ...)     //
// - Fazer um insertion Sort para vários valores de h até que h=1                      //
//                                                                                     //
// É um algoritmo de ordenação complexo e o consumo de tempo depende da sequência      //
// escolhida para h                                                                    //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "vetor.h" // Definião do vetor e troca()
#include <stdlib.h> // malloc()
#include <stdio.h>
#define v(i) ((char *) v + (i) * sz)

// Ordena o vetor v com a ordem estabelecida pela função compara
// A sequência de incrementos será 1 4 13 40 121 ... (k_i = 3*k_(i-1) + 1)
void shellSort1 (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    int i, j, h;
    void *atual = malloc (sz);
    for (h = 1; h < n/9; h = 3*h + 1);
    for ( ; h > 0; h /= 3)
        // Vamos inserir v[i] na parte ordenada
        for (i = h; i < n; i++) {
            copiaMemoria (atual, v(i), sz);
            // Empurra os elementos pra esquerda até chegar na posição do inserido
            for (j = i - h; j >= 0 && compara(v(j), atual) > 0; j -= h)
                copia(v, j + h, j, sz);
            copiaMemoria (v(j + h), atual, sz);
        }
    free (atual);
}

// Ordena o vetor v com a ordem estabelecida pela função compara
// A sequência de incrementos será 1 8 23 77 281 1073 ... (k_i = 4^(i+1) + 3*2^i + 1)
int h2 (int i) {
    if (i < 0) return 1;
    int x, ret, exp;
    for (x = 4, exp = 1; exp <= i; x *= 4, exp++);
    ret = x;
    for (x = 1, exp = 0; exp < i; x *= 2, exp++);
    ret += 3*x;
    return ret + 1;
}
void shellSort2 (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    int i, j, h_i, h;
    void *atual = malloc (sz);
    for (h_i = 0; h2(h_i) < n/9; h_i++);
    for ( ; h_i >= -1; h_i--) {
        h = h2 (h_i);
        // Vamos inserir v[i] na parte ordenada
        for (i = 0; i < n; i++) {
            // Empurra os elementos pra esquerda até chegar na posição do inserido
            copiaMemoria (atual, v(i), sz);
            for (j = i - h; j >= 0 && compara(v(j), atual) > 0; j -= h)
                copia(v, j + h, j, sz);
            copiaMemoria (v(j + h), atual, sz);
        }
    }
    free (atual);
}

// Ordena o vetor v com a ordem estabelecida pela função compara
// A sequência de incrementos será 1 2 3 4 6 9 8 12 18 27 ... (monta um triangulinho)
int h3 (int i) {
    if (i == 0) return 1;
    int x, j, exp2, exp3, exp;
    for (j = 0; (j + 1)*(j + 2)/2 < i + 1; j++);
    exp3 = i - j*(j+1)/2;
    exp2 = j - exp3;
    for (x = 1, exp = 0; exp < exp2; x *= 2, exp++);
    for (exp = 0; exp < exp3; x *= 3, exp++);
    return x;
}
void shellSort3 (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    int i, j, h_i, h;
    void *atual = malloc (sz);
    for (h_i = 0; h3(h_i) < n/9; h_i++);
    for ( ; h_i >= 0; h_i--) {
        h = h3 (h_i);
        // Vamos inserir v[i] na parte ordenada
        for (i = 0; i < n; i++) {
            // Empurra os elementos pra esquerda até chegar na posição do inserido
            copiaMemoria (atual, v(i), sz);
            for (j = i - h; j >= 0 && compara(v(j), atual) > 0; j -= h)
                copia(v, j + h, j, sz);
            copiaMemoria (v(j + h), atual, sz);
        }
    }
    free (atual);
}