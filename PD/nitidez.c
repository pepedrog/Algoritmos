////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                    //
//                                      Imprimir Nitidamente                                          //
//                                                                                                    //
// Considere o problema de imprimir nitidamente um parágrafo em uma impressora.                       //
// O texto de entrada é uma sequência de n palavras de comprimentos l[0], ..., l[n - 1]               //
//                                                                                                    //
// Queremos imprimir esse parágrafo com nitidez em uma série de linhas que contêm no máximo           //
// M caracteres cada uma.                                                                             //
// Nosso critério de “nitidez”  ́e dado a seguir.                                                      //
//                                                                                                    //
// Se uma determinada linha contém palavras de i até j, onde i ≤ j                                    //
// e deixamos um espaço entre as palavras, o número de espaços extras no final da linha é            //
//                                                                                                    //
//    M − j + i − (l[i] + .. + l[j])                                                                  //
//                                                                                                    //
// que deve ser não-negativo para que as palavras caibam na linha. Desejamos minimizar a soma,       //
// sobre todas as linhas exceto a última, do cubo do número de espaços extras no final das linhas.   //
//                                                                                                    //
// Problema 15-2 do CLRS                                                                              //
//                                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#define INF __INT_MAX__

int DEBUG = 0;

// Função auxiliar a³
int cubo( int a) {
    return a*a*a;
}

// Imprime as n palavras em l linhas de até M caracteres
// do jeito nítido indicado pela tabela veio 
void imprimeTela( char* palavra[], int** veio, int* sp, int n, int M, int linha) {
    
    // Pilha pra inverter a ordem das linhas
    int* pilha = malloc( linha * sizeof( int));
    int tam = 0;
    pilha[tam++] = veio[linha--][n - 1];
    while(linha >= 0) {
        pilha[tam] = veio[linha--][pilha[tam - 1]]; 
        tam++;
    }
    pilha[tam - 1] = -1;

    // Para cada linha
    for(int l = tam - 1; l > 0; l--) {
        printf("| ");
        // Imprime as palavras dessa linha
        for( int k = pilha[l] + 1; k <= pilha[l - 1]; k++) printf( "%s ", palavra[k]);
        // Coloca os espaços em branco no final
        int espbranco = M - pilha[l - 1] + pilha[l] - sp[pilha[l - 1]] + sp[pilha[l]];
        for(int i = 0; i < espbranco; i++) printf(" "); printf(" |\n");
    }
    // Imprime a ultima linha
    printf("| ", palavra[pilha[0]]);
    for( int k = pilha[0] + 1; k < n; k++) printf( "%s ", palavra[k]);
    int espbranco = M - n + 1 + pilha[0] - sp[n-1] + sp[pilha[0]];
    for(int i = 0; i < espbranco; i++) printf(" "); printf(" |\n");

    free( pilha);
}

// Printa a tabela da Programação Dinâmica
// Que indica o custo de cada impressão
void printaTabela( int** custo, int** veio, int n) {
    for( int i = 0; i < n; ++i) {
        for( int j = 0; j < n; j++) 
            if(custo[i][j] == INF) printf( "INF\t"); 
            else printf("%d|%d\t", custo[i][j], veio[i][j]);
        printf("%\n");
    }
}

// Calcula com um algoritmo de programação dinâmica
// Um jeito nítido de imprimir as n palavras
int imprimeNitido( char* palavra[], int* l, int* sp, int n, int M) {

    // Se cabe tudo na primeira linha, o custo é 0
    if( M >= sp[n-1] + n - 1)
        return 0;

    // Alocação das tabelas da PD

    // A tabela custo terá a forma:
    //
    // custo[li][k] := melhor custo de imprimir k palavras em li linhas (INF se for impossível)
    // veio[li][k] := última palavra da linha li - 1 (para rastrear a PD)
    int** custo = malloc( n * sizeof( int*));
    int** veio = malloc( n * sizeof( int*));
    for( int i = 0; i < n; i++){
        custo[i] = malloc( n * sizeof( int));
        veio[i] = malloc( n * sizeof( int));
    }

    // Inicialização da primeira linha
    for( int k = 0; k < n; k++) {
        // Calculo dos espaços em branco
        custo[0][k] = cubo( M - k - sp[k]);
        // Se a palavra não cabe na linha
        if( custo[0][k] < 0) custo[0][k] = INF;
    }

    // Preenchimento da tabela para as outras linhas
    for( int k = 1; k < n; k++) {
        for( int li = 1; li <= k; li++) {
            // A priori não cabe
            custo[li][k] = INF;
            // Calcula o custo conforme a formula da recorrência
            // custo[li][k] = min_i{ M - k + i + 1 - (l[i] + ... + l[k]) }
            for( int i = li - 1; i < k; i++) {
                int clinha = cubo( M - k + i + 1 - (sp[k] - sp[i]));

                // Não considera o custo da última linha (linha da ultima palavra)
                if( k == n - 1 && clinha > 0) clinha = 0;
                // Se a palavra couber na linha e a linha anterior for valida (pra não dar overflow)
                if( clinha >= 0 && custo[li - 1][i] < INF) 
                    // Calcula o mínimo
                    if( custo[li][k] > custo[li-1][i] + clinha) {
                        custo[li][k] = custo[li-1][i] + clinha;
                        veio[li][k] = i;
                    }
            }
        }
    }

    //Decide qual é o menor custo para as n palavras
    int menor = custo[0][n-1];
    int linha = n;
    for(int j = 0; j < n; j++) 
        if( menor > custo[j][n-1]) {
            menor = custo[j][n-1];
            linha = j;
        }

    // Ótimo para debugar
    if(DEBUG) printaTabela( custo, veio, n);

    imprimeTela( palavra, veio, sp, n, M, linha);
    
    for(int i = 0; i < n; i++) {
        free( custo[i]);
        free( veio[i]);
    }
    free( custo);
    free( veio);

    return menor;

}

// Versão para debugar com as palavras
int main( int argc, char* argv[]) {

    int n, M;
    int* l;
    int* sp;
    char** palavra;

    if( argc > 1) DEBUG = 1;
    scanf("%d", &n);
    palavra = malloc( n * sizeof( char* ));
    l = malloc( n* sizeof( int));
    sp = malloc( n * sizeof( int));

    for( int i = 0; i < n; i++) {
        l[i] = 0;
        palavra[i] = malloc( 15 * sizeof( char));
        // Le a palavra e guarda o tamanho
        char c = getchar() ;
        while( c == ' ' || c == '\n') c = getchar();
        while( c != ' ' && c != '\n' && c != '\0') {
            palavra[i][l[i]++] = c; 
            c = getchar();
        }
        // Atualiza a soma parcial
        if(i > 0) sp[i] = sp[i-1] + l[i];
        else sp[i] = l[i];
    }

    scanf("%d", &M);

    int custo = imprimeNitido( palavra, l, sp, n, M);
    // printf("Custo da impressão: %d\n", imprimeNitido( palavra, l, sp, n, M));
    return 0;
}

// Algoritmo Cúbico em n