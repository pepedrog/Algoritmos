#include <stdio.h>
#include <stdlib.h>

#define DIAGONAL 1
#define CIMA 2
#define ESQ 3
static int DEBUG = 0;

void printaTabela( int** c, int n, int m) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; j++) 
            printf( "%d\t", c[i][j]);
        printf( "\n");
    }
}

void subseqComum( char *X, int n, char *Y, int m) {
    
    int i; // Iteradores das linhas
    int j; // Iteradores das colunas
    // Tabela do comprimento da subsequência
    int **c = malloc( (n + 1) * sizeof( int*));
    for (i = 0; i <= n; i++) c[i] = malloc( (m + 1) * sizeof( int *));
    // Tabela de rastreio da subsequência
    int **track = malloc( (n + 1) * sizeof( int*));
    for (i = 0; i <= n; i++) track[i] = malloc( (m + 1) * sizeof( int *));
    // Inicializando a tabela
    for (i = 1; i <= n; i++) c[i][0] = 0;
    for (j = 0; j <= m; j++) c[0][j] = 0;
    // Preenchendo a tabela
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (X[i - 1] == Y[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1,
                track[i][j] = DIAGONAL;
            else if (c[i - 1][j] >= c[i][j - 1])
                c[i][j] = c[i - 1][j],
                track[i][j] = CIMA;
            else c[i][j] = c[i][j - 1],
                track[i][j] = ESQ;
    
    if (DEBUG) printaTabela(c, n, m);
}

void get( char **s, int n) {
    *s = malloc( n * sizeof( char));
    for (int i = 0; i < n; i++) {
        if ((*s)[i - 1] == '\n') i--; 
        (*s)[i] = getc(stdin);
    }
}

int main( int argc) {
    char *X, *Y;
    int n, m, i;
    if (argc > 1) DEBUG = 1;
    scanf("%d", &n);
    scanf("%d", &m);
    get(&X, n);
    get(&Y, m);

    if (DEBUG) printf("X = %s\n", X), printf("Y = %s\n", Y);

    subseqComum( X, n, Y, m);
}