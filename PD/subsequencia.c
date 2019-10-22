////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                    //
//                                    Maior Subsequência Comum                                        //
//                                                                                                    //
// Considere o problema de imprimir nitidamente um parágrafo em uma impressora.                       //
// O texto de entrada é uma sequência de n palavras de comprimentos l[0], ..., l[n - 1]               //
//                                                                                                    //
// Queremos imprimir esse parágrafo com nitidez em uma série de linhas que contêm no máximo           //
// M caracteres cada uma.                                                                             //
// Nosso critério de “nitidez”  ́e dado a seguir.                                                      //
//                                                                                                    //
// Se uma determinada linha contém palavras de i até j, onde i ≤ j                                    //
// e deixamos um espaço entre as palavras, o número de espaços extras no final da linha é             //
//                                                                                                    //
//    M − j + i − (l[i] + .. + l[j])                                                                  //
//                                                                                                    //
// que deve ser não-negativo para que as palavras caibam na linha. Desejamos minimizar a soma,        //
// sobre todas as linhas exceto a última, do cubo do número de espaços extras no final das linhas.    //
//                                                                                                    //
// Problema 15-2 do CLRS                                                                              //
//                                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>

enum direcao { DIAGONAL, CIMA, ESQ };
static int DEBUG = 0;

// Função auxiliar para printar a tabela da programação dinâmica
// Pode ser usada para debugar/simular o algoritmo
void printaTabela( int** c, int ** track, int n, int m) {
    int i, j;
    for (i = 0; i <= n; ++i) {
        for (j = 0; j <= m; j++) 
            printf( "%d|%d\t", c[i][j], track[i][j]);
        printf( "\n");
    }
}

// Função que percorre a tabela no caminho reverso encontrando
// a maior subsequência obtida pelo algoritmo. 
// Recebe a tabela de rastreio e devolve a maior subsequência 
// comum de X e Y (que terá comprimento c)
char *rastreiaSeq( int **track, int n, int m, int c, char *X) {

    // String que vai guadando a subsequencia rastreada
    char *seq = malloc( c * sizeof( char));
    for (int i = 0; i < c; i++) seq[i] = ' ';
    // Indice que estamos na matriz, começando do final
    int atual[2] = { n, m };
    // Percorre enquanto não chega numa extremidade da matriz
    while (atual[0] != 0 && atual[1] != 0) {
        if (DEBUG) printf( "atual = { %d %d }", atual[0], atual[1]);
        // Vai para direção indicada no rastreio
        switch (track[atual[0]][atual[1]]) {
            case CIMA:
                atual[0]--;
                break;
            case ESQ:
                atual[1]--;
                break;
            case DIAGONAL:
                // Sempre veio da diagonal, então a letra faz parte da subsequencia
                if (DEBUG) printf( "\t%c", X[atual[0] - 1]);
                // Como percorremos do final ao começo, temos que por no final da seq
                seq[--c] = X[atual[0] - 1];
                atual[0]--;
                atual[1]--;
                break;                
        }
        if (DEBUG) printf("\n");  
    }
    return seq;
}

void maiorSubseqComum( char *X, int n, char *Y, int m) {
    
    int i; // Iteradores das linhas
    int j; // Iteradores das colunas
    
    // Tabela para a programação dinâmica que guarda em c[i][j] 
    // o comprimento da maior subsequência comum de X[1 .. i] e Y [1 .. j]
    int **c = malloc( (n + 1) * sizeof( int*));
    for (i = 0; i <= n; i++) c[i] = malloc( (m + 1) * sizeof( int *));
    // Tabela de rastreio da subsequência
    int **track = malloc( (n + 1) * sizeof( int*));
    for (i = 0; i <= n; i++) track[i] = malloc( (m + 1) * sizeof( int *));
    // Inicializando a tabela (subsequencia vazia)
    for (i = 1; i <= n; i++) c[i][0] = 0;
    for (j = 0; j <= m; j++) c[0][j] = 0;
    // Preenchendo a tabela
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)

            // Preenche a posição [i,j] de acordo com a regra da recorrência
            // c[i,j] = c[i - 1, j - 1] + 1 , se X[i] == Y[j]
            // c[i,j] = max( c[i,j - 1], c[i - 1,j]) c.c
            //
            // Ou seja, a se os dois ultimos são iguais, alguma subseq maxima
            // contem esse par, se não, a maior subseq é maior desconsiderando
            // algum desses dois ultimos.
            
            if (X[i - 1] == Y[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1,
                track[i][j] = DIAGONAL;
            else if (c[i - 1][j] > c[i][j - 1])
                c[i][j] = c[i - 1][j],
                track[i][j] = CIMA;
            else c[i][j] = c[i][j - 1],
                track[i][j] = ESQ;
    
    // Depois de preencher a tabela, o campo c[n][m] guarda o
    // comprimento da maior subsequencia comum de X e Y, basta rastrear as letras.
    if (DEBUG) printaTabela( c, track, n, m);
    printf( "%s\n", rastreiaSeq( track, n, m, c[n][m], X));
}

// Função auxiliar que lê a string da entrada em *s
void get( char **s, int n) {
    *s = malloc( n * sizeof( char));
    for (int i = 0; i < n; i++) {
        if ((*s)[i - 1] == '\n') i--; 
        (*s)[i] = getc(stdin);
    }
}

int main( int argc, char **argv ) {
    char *X, *Y;
    int n, m;
    if (argc > 1) DEBUG = 1;
    // Le a entrada
    scanf("%d", &n);
    scanf("%d", &m);
    get(&X, n);
    get(&Y, m);
    if (DEBUG) printf("X = %s\n", X), printf("Y = %s\n", Y);
    // Chama o algoritmo
    maiorSubseqComum( X, n, Y, m);
}