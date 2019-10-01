//////////////////////////////////////////////////////////////////////////////
//																			//
//					Parentização de produto de Matrizes						//
// 																			//
// Sabemos que a multiplicação de matrizes é associativa, isto é			//
// 				( A * B ) * C = A * ( B * C )								//
//																			//
// Porém, o custo, em multiplicações escalares, de cada uma das maneiras	//
// de realizar o produto varia de acordo com as dimensões das matrizes.		//
// 																			//
// Queremos uma sequência de produtos ótima que minimiza o custo de fazer	//
// essas multiplicações														//
//																			//
// Recebe um número n de matrizes e uma lista de n + 1 dimensões dim,		//
// onde a matriz i tem dimensões dim[i] x dim[i + 1].						//
//																			//
// Devolve na saida padrão uma string com as matrizes e parenteses,			//
// indicando a ordem das operações.											//
// 																			//
// Algoritmo de programação dinâmica que consome O(n^3) unidades de tempo.	//
//																			//
//////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>

#define INF __INT_MAX__

int DEBUG = 0;

void recuperaTrack( int** track, int n) {
	int ini = 0, fim = 6 * n - 6;
	int mIni = 0, mFim = n - 1;
	int prox = track[mIni][mFim];
	char* s = malloc( (6 * n - 4) * sizeof( char));
	while( mFim > mIni) {
		s[ini++] = '(';
		s[fim--] = ')';
		s[ini++] = ' ';
		s[fim--] = ' ';
		if( prox == mIni) {
			s[ini++] = 'A' + mIni;
			s[ini++] = ' ';
			mIni++;
		}
		else {
			s[fim--] = 'A' + mFim;
			s[fim--] = ' ';
			mFim--;
		}Algoritmo de programação dinâmica que consome 
		prox = track[mIni][mFim];
		s[fim - 2];
	}
	s[fim] = 'A' + mFim;
	s[ 6 * n - 5] = '\0';
	printf( "%s", s);
	free( s);
}

void printaTabela( int** m, int** track, int n) {
	for( int i = 0; i < n; i++) {
		for( int j = 0; j < n; j++)
			printf( "%d|%d\t", m[i][j], track[i][j]);
		printf( "\n");
	}
}

void melhorSequencia( int* dim, int n) {
	// Inicializa a matriz da PD
	int** m = malloc( n * sizeof( int*));
	for( int i = 0; i < n; i++) {
		m[i] = malloc( n * sizeof( int));
		m[i][i] = 0;
	}
	int** track = malloc( n * sizeof( int*));
	for( int i = 0; i < n; i++) {
		track[i] = malloc( n * sizeof( int));
	}
	int i; // linha
	int j; // coluna
	int l; // diagonal
	int q; // custo dessa parametrização

	for( int l = 1; l < n; l++) {
		for( int i = 0; i < n - l; i++) {
			j = i + l;
			m[i][j] = INF;
			for( int k = i; k < j; k++) {
				q = m[i][k] + dim[i] * dim[k + 1] * dim[j + 1] + m[k + 1][j];
				if( q < m[i][j]) {
					track[i][j] =  k;
					m[i][j] = q;
				}
			}
		}
	}

	if( DEBUG) printaTabela( m, track, n);
	recuperaTrack( track, n);
}

int main( int argc, char* argv[]) {
	int n;
	int* dim;

	if( argc > 1) DEBUG = 1;
	scanf( "%d", &n);
	dim = malloc( (n + 1) * sizeof( int));

	for( int i = 0; i <= n; i++) 
		scanf( "%d", &dim[i]);

	melhorSequencia( dim, n);
	return 0;
}
