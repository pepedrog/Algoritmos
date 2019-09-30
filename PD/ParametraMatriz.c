#include <stdio.h>
#include <stdlib.h>

#define INF __INT_MAX__

int DEBUG = 0;

void melhorSequencia( int* dim, int n) {
	// Inicializa a matriz da PD
	int** m = malloc( n * sizeof( int*));
	for( int i = 0; i < n; i++) {
		m[i] = malloc( n * sizeof( int));
		m[i][i] = 0;
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
				if( q < m[i][j])
					m[i][j] = q;
			}
		}
	}

	for( i = 0; i < n; i++) {
		for( j = 0; j < n; j++)
			printf( "%d\t", m[i][j]);
		printf( "\n");
	}
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
