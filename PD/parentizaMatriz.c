//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//                    Parentização de produto de Matrizes                   //
//                                                                          //
// Sabemos que a multiplicação de matrizes é associativa, isto é            //
//                 ( A * B ) * C = A * ( B * C )                            //
//                                                                          //
// Porém, o custo, em multiplicações escalares, de cada uma das maneiras    //
// de realizar o produto varia de acordo com as dimensões das matrizes.     //
//                                                                          //
// Queremos uma sequência de produtos ótima que minimiza o custo de fazer   //
// essas multiplicações                                                     //
//                                                                          //
// Recebe um número n de matrizes e uma lista de n + 1 dimensões dim,       //
// onde a matriz i tem dimensões dim[i] x dim[i + 1].                       //
//                                                                          //
// Devolve na saida padrão uma string com as matrizes e parenteses,         //
// indicando a ordem das operações.                                         //
//                                                                          //
// Algoritmo de programação dinâmica que consome O(n^3) unidades de tempo.  //
// E O(n^2) em espaço.                                                      //
// Poderia melhorar as constantes, mas preferi a simplicidade do código     //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>

#define INF __INT_MAX__

int DEBUG = 0;

// Função auxiliar pra printar a tabela (usada pra debugar)
void printaTabela( int** m, int** track, int n) {
	for( int i = 0; i < n; i++) {
		for( int j = 0; j < n; j++)
			printf( "%d|%d\t", m[i][j], track[i][j]);
		printf( "\n");
	}
}

// Função que percorre a tabela ao contrário para reconstruir o produto final
void recuperaTrack( int** track, int n) {
	// Esse código exige um entendimento de como a tabela track
	// foi construida. Os índices aqui são meio mágicos.
	
	// Íncides da string construida
	int ini = 0, fim = 6 * n - 6;
	// Índices das matrizes das pontas da string
	int mIni = 0, mFim = n - 1;
	// Matriz que ficou de fora do resto do produto
	int prox = track[mIni][mFim];
	// String de retorno
	char* s = malloc( (6 * n - 4) * sizeof( char));
	// Enquanto não coloca todas as matrizes
	while (mFim > mIni) {
		// Coloca os parenteses em volta desse produto 
		s[ini++] = '(';
		s[fim--] = ')';
		s[ini++] = ' ';
		s[fim--] = ' ';
		// Coloca a matriz que ficou de fora do produto
		if (prox == mIni) {
			s[ini++] = 'A' + mIni;
			s[ini++] = ' ';
			mIni++;
		}
		else {
			s[fim--] = 'A' + mFim;
			s[fim--] = ' ';
			mFim--;
		}
		// Define a próxima matriz
		prox = track[mIni][mFim];
		s[fim - 2];
	}
	// Coloca a última matriz
	s[fim] = 'A' + mFim;
	// Imprime e libera
	printf( "%s\n", s);
	free( s);
}

// Recebe a o vetor das n + 1 dimensões das matrizes e printa
// a melhor sequência de multiplicação delas.
int melhorSequencia( int* dim, int n) {
	// A matriz m[i][j] guarda o custo da melhor multiplicação Ai...Aj
	// (Matriz de recorrência da PD)
	int** m = malloc( n * sizeof( int*));
	// Inicializa a matriz e preenche a diagonal
	// m[i][i] = 0 (não multiplicamos uma só matriz)
	for (int i = 0; i < n; i++) {
		m[i] = malloc( n * sizeof( int));
		m[i][i] = 0;
	}
	// Inicializa matriz de rastreio
	int** track = malloc( n * sizeof( int*));
	for (int i = 0; i < n; i++) {
		track[i] = malloc( n * sizeof( int));
	}

	// Começando a preencher a tabela:
	int i; // linha
	int j; // coluna
	int l; // diagonal
	int q; // custo dessa parametrização
	// Preenchendo pelas diagonais, de Noroeste para Sudeste
	for (int l = 1; l < n; l++) {
		for (int i = 0; i < n - l; i++) {
			// Com a linha e adiagonal, encontramos a coluna
			j = i + l;
			// Encontra o menor custo de m[i][j]
			m[i][j] = INF;
			// k é aonde vai os parênteses mais externos, que divide o produto em 2
			// Testamos colocalo entre cada para entre i e j para achar o melhor 
			for( int k = i; k < j; k++) {
				// Cálculo do custo m[i][j] se o parentes for em k
				// m_k[i][j] = Custo do primeiro produto m[i][k] +
				//           Custo de multiplicar os dois produtos d[i]*d[k+1]*d[j+1] +
				//           Custo do segundo produto m[k+1][j]
				q = m[i][k] + dim[i] * dim[k + 1] * dim[j + 1] + m[k + 1][j];
				// Se encontrei um custo melhor que o atual, guarda ele e da onde veio
				if( q < m[i][j]) {
					track[i][j] =  k;
					m[i][j] = q;
				}
			}
		}
	}
	// Agora que encontrei o melhor custo m[0][n - 1], recupera da onde ele veio
	if (DEBUG) printaTabela( m, track, n);
	recuperaTrack( track, n);
	// Retorna o custo
	return m[0][n - 1];
}

int main( int argc, char* argv[]) {
	int n;
	int* dim;
	
	if (argc > 1) DEBUG = 1;
	// Le e aloca todos os dados
	scanf( "%d", &n);
	dim = malloc( (n + 1) * sizeof( int));
	for (int i = 0; i <= n; i++) 
		scanf( "%d", &dim[i]);
	// Roda o algoritmo
	int m = melhorSequencia (dim, n);
	printf ("Número de múltiplicações escalares = %d\n", m);
	return 0;
}
