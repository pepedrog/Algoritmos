///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//                         Geometria Computacional                           //
//                                                                           //
// Esse arquivo fornece uma interface para diversas estruturas e algoritmos  //
// geométricos (em duas dimensões).                                          //
//                                                                           //
// As funções mais simples de manipulação de pontos estão implementadas no   //
// arquivo ponto.c. Os demais algoritmos estão em arquivos .c individuais.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// OBS: As boas práticas de programação recomendam trabalharmos com ponteiros
// para as estruturas. Entretanto, escolhi lidar com as estruturas para não
// precisar engordar os cógigos com gerenciamento de memória.

typedef int bool;
#define false 0
#define true 1

// Estrutura que usaremos para representar um ponto (x, y)
typedef struct { float x, y; } ponto;

// Estrutura para guardar um par de pontos
typedef struct { ponto p1, p2; } par;

// Um par de pontos pode determinar um segmento de reta
typedef par segmento;

// Função para facilitar a inicialização de um ponto
ponto novoPonto (float x, float y);

// Função que retorna o quadrado distância euclidiana entre os pontos a e b
float dist2 (ponto a, ponto b);

// Função que calcula o dobro da área do triângulo dado por a, b e c
// Se os pontos estão em sentido anti-horário, a responta será positiva,
// Se estiverem em sentido horário, será negativa.
float area2 (ponto a, ponto b, ponto c);

///////////////////////////////////////////////////////////////////////////////
// Predicados Geométricos
///////////////////////////////////////////////////////////////////////////////

// Função que retorna se o ponto c está estritamente à esquerda do segmento ab
bool esquerdaEstrita (segmento ab, ponto c);

// Função que retorna se o ponto c está à esquerda ou é colinear ao segmento ab
bool esquerda (segmento ab, ponto c);

// Função que retorna se o ponto c está estritamente à direita do segmento ab
bool direitaEstrita (segmento ab, ponto c);

// Função que retorna se o ponto c está à direita ou é colinear ao segmento ab
bool direita (segmento ab, ponto c);

// Função que retorna se os pontos a, b, c são colineares
bool colineares (ponto a, ponto b, ponto c);

// Função que retorna se o ponto c pertence ao segmento ab
bool entre (segmento ab, ponto c);

// Função que retorna se o segmento ab e o segmento cd se intersectam em um ponto
// no interior deles (não considera as extremidades)
bool intersectaProp (segmento ab, segmento cd);

// Função que retorna se o segmento ab e o segmento cd se intersectam
bool intersecta (segmento ab, segmento cd);

///////////////////////////////////////////////////////////////////////////////
// Algoritmos avulsos de pontos e segmentos
///////////////////////////////////////////////////////////////////////////////

// Função que recebe um vetor de pontos P[1..n]
// e retorna um par de pontos com distância mínima (Algoritmo Shamos-Hoey)
par pontosProximos (ponto *P, int n);

///////////////////////////////////////////////////////////////////////////////
// Algoritmos de polígonos
///////////////////////////////////////////////////////////////////////////////

// Polígono: Um polígono é uma região fechada do plano delimitada por uma 
//           sequência de pontos ligados por arestas que não se intersectam.
typedef struct { 
    int n;    // Quantidade de vértices
    ponto *v; // Vetor de vértices, em sequência e em sentido anti-horário
} poligono;

// Função que cria um polígono de n vértices
poligono novoPoligono (int n, ponto v[]);

// Diagonal: Uma diagonal de um polígono p é um segmento de reta dado por dois
//           vértices de p que está inteiramente contido no polígono e não 
//           intersecta propriamente a borda. 
typedef struct {
    int i, j; // índices dos vértices do polígono que formam a diagonal
} diagonal;

// Função que retorna se um segmento ab intersecta propriamente a borda do polígono
bool intersectaBorda (poligono p, segmento ab);

// Função que retorna se o segmento formado pelos vértices i e j do polígono
// é uma diagonal de p
bool eDiagonal (poligono p, int i, int j);

// Triangulação: Uma partição do polígono em triangulos, pode ser dado
//               por um conjunto maximal de diagonais que não se intersectam
//               Representaremos por um vetor de diagonais, int[2][n]

// Função que retorna um vetor de n-3 diagonais (um int[2] dos índices dos vértices
// do polígono) que descrevem uma triangulação
// (Algoritmo que usa orelhas, O(n^2)) 
diagonal *triangulacao2 (poligono p);
