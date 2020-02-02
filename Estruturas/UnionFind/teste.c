// Programinha pra testar as diferentes implementações do Union Find

#include "unionFind.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Macro pra não precisar recopiar esse trecho pra cada implementação
// Cronometra o tempo para fazer as 2*n unioes
#define processa(nome)             \
    nome nome##1 = cria##nome (n);       \
    t = clock();                    \
    for (int i = 0; i < 2*n; i++)   \
        union##nome (nome##1, pares[i][0], pares[i][1]); \
    printf ("%s:\t %fs\n", #nome, (clock() - t) / (float) CLOCKS_PER_SEC)

int main () {
    clock_t t;
    int n;
    scanf ("%d", &n);
    int **pares; // Os pares que serão unidos
    // tem que guardar para todas as implementações terem a mesma entrada.

    pares = malloc (2*n * sizeof (int *));
    for (int i = 0; i < 2*n; i++) pares[i] = malloc (2 * sizeof (int));
    // sorteia os pares (2*n deve ser suficiente pra unir todos)
    for (int i = 0; i < 2*n; i++) {
        // Veja notas sobre números aleatórios do professor Feofiloff
        pares[i][0] = (double) rand() / ((double) RAND_MAX + 1) * n; 
        pares[i][1] = (double) rand() / ((double) RAND_MAX + 1) * n; 
    }

    // Une os pares pra cada implementação
    processa (QF);
    processa (QU);
    processa (WQU);
    processa (HQU);
    processa (QUPH);
    processa (QUPS);
    processa (QUPC);
}

// Resultados para n = 50000
//
//  QF:	   120.104195s
//  QU:	   26.406813s
//  WQU:   0.059310s
//  HQU:   0.042778s
//  QUPH:  0.023589s
//  QUPS:  0.022229s
//  QUPC:  0.025537s
//
//  Da pra perceber bem o efeito do log e do log*
//  Lembrando que os dados são aleatórios então esses testes não significam muita coisa,
//  Mas é legal ter essa comprovação empírica da commplexidade.
