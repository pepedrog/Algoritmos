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

// Estrutura que usaremos para representar um ponto (x, y)
typedef struct { float x, y; } ponto;

// Estrutura para guardar um par de pontos
typedef struct { ponto p1, p2; } par;

// Estrutura que usaremos para representar um polígono
typedef struct { 
    int n;    // Quantidade de vértices
    ponto *v; // Vetor de vértices, onde os vértices adjacentes nesse vetor
              // são adjacentes no polígono 
} poligono;

// Função para facilitar a inicialização de um ponto
ponto novoPonto (float x, float y);

// Função que retorna o quadrado distância euclidiana entre os pontos p1 e p2
float dist2 (ponto p1, ponto p2);

// Função que calcula o dobro da área do triângulo dado por p1, p2 e p3
// Se os pontos estão em sentido anti-horário, a responta será positiva,
// Se estiverem em sentido horário, será negativa.
float area2 (ponto p1, ponto p2, ponto p3);

// Função que recebe um vetor de pontos P[1..n]
// e retorna um par de pontos com distância mínima (Algoritmo Shamos-Hoey)
par pontosProximos (ponto *P, int n);
