// Programinha pra testar as diferentes implementações do Union Find

#include "unionFind.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Quantidade de elementos
#define N 10000

// Macro pra não precisar recopiar esse trecho pra cada implementação
// Cronometra o tempo para fazer as 2*N unioes
#define processa(nome)             \
    nome nome##1 = cria##nome (N);       \
    t = clock();                    \
    for (int i = 0; i < 2*N; i++)   \
        union##nome (nome##1, pares[i][0], pares[i][1]); \
    printf ("%s:  %fs\n", #nome, (clock() - t) / (float) CLOCKS_PER_SEC)

int main () {
    clock_t t;
    int pares[2*N][2]; // Os pares que serão unidos
    // tem que guardar para todas as implementações terem a mesma entrada.
    
    // sorteia os pares (2*N deve ser suficiente pra unir todos)
    for (int i = 0; i < 2*N; i++) {
        pares[i][0] = rand() / RAND_MAX * (N - 1);
        pares[i][1] = rand() / RAND_MAX * (N - 1);
    }

    // Une os pares pra cada implementação
    processa (QF);
    processa (QU);
}