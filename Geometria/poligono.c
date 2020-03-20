///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//                         Algoritmos de polígonos                           //
//                                                                           //
// Implementações das funções de polígonos descritas em geometria.h          //
// As definições e interface estão também nesse arquivo                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "geometria.h"
#include <stdio.h> // debug
#include <stdlib.h>

// Função que cria um polígono com n vértices
poligono novoPoligono (int n, ponto v[]) {
    return (poligono) {n, v};
}

// Função que retorna se um segmento ab intersecta propriamente a borda do polígono
bool intersectaBorda (poligono p, segmento ab) {
    int k, l;
    segmento borda;
    // Testa interseção com todas as bordas kl do polígono
    for (k = 0; k < p.n; k++) {
        l = (k + 1) % p.n;
        borda.p1 = p.v[k];
        borda.p2 = p.v[l];
        // desconsidera o caso onde o k ou o l são os extremos do segmento
        if (!(p.v[k].x == ab.p1.x && p.v[k].y == ab.p1.y)  // k != p1
            &&  !(p.v[k].x == ab.p2.x && p.v[k].y == ab.p2.y)  // k != p2
            &&  !(p.v[l].x == ab.p1.x && p.v[l].y == ab.p1.y)  // l != p1
            &&  !(p.v[l].x == ab.p2.x && p.v[l].y == ab.p2.y)) // l != p2
            if (intersecta (borda, ab))
                return true;
    }
    return false;
}

// Função que retorna se o segmento formado pelos vértices i e j do polígono
// é uma diagonal 
bool eDiagonal (poligono p, int i, int j) {
    // Para um segmento ser uma diagonal tem que 
    // 1- Estar pra dentro do polígono
    // 2- Não intersectar a borda do polígono
    segmento ij;
    ij = (segmento) {p.v[i], p.v[j]};

    // 1 - Testando se está pra dentro
    bool estaDentro;

    // Os vértices i-1, i, i+1 são uma ponta do polígono (u, i, w)
    // Se eu viro pra esquerda na ponta u i w, então o ângulo é convexo (< 90)
    int u = (i - 1 + p.n)%p.n, w = (i + 1)%p.n;
    segmento ui; 
    ui = (segmento) {p.v[u], p.v[i]};
    if (esquerda (ui, p.v[w]))
        // Se o angulo é convexo, 
        // o vértice u tem que estar a esquerda de ij e o w a direita
        estaDentro = (esquerdaEstrita (ij, p.v[u]) && direitaEstrita (ij, p.v[w]));
    else
        // Se o ângulo é aberto, temos que verificar se o segmento ij
        // não está no angulo fechado do lado de fora
        estaDentro = !(esquerda (ij, p.v[w]) && direita (ij, p.v[u]));

    // Agora junta tudo
    return (estaDentro && !intersectaBorda (p, ij));
}

// Função que retorna um vetor de n-3 diagonais (um int[2] dos índices dos vértices
// do polígono) que descrevem uma triangulação
diagonal *triangulacao2 (poligono p) {
    int i, n = p.n;
    diagonal *triang = malloc ((n - 3) * sizeof (diagonal));

    // Vetor que guarda quais vértices são orelhas (as pontas do polígono)
    // i é uma ponta de orelha se i-1 e i+1 formam uma diagonal
    bool *orelha = malloc (n * sizeof (bool));
    // Vetores que diram quais vértices são adjacentes na parte não triangulada (lista)
    int *prev = malloc (n * sizeof (int));
    int *prox = malloc (n * sizeof (int));
    
    // Pré processamento desses vetores
    for (i = 0; i < n; i++) {
        prev[i] = (i - 1 + n)%n; //+n evita negativo
        prox[i] = (i + 1)%n;
        orelha[i] = eDiagonal (p, prev[i], prox[i]); 
    }

    // Agora começa a triangulação
    int d = 0;
    i = 0;
    while (d < n - 3) {
        // Procuramos uma orelha e guardamos a diagonal
        while (!orelha[i]) i = prox[i];
        triang[d++] = (diagonal) { prev[i], prox[i] } ;
        // tira i do poligono
        prox[prev[i]] = prox[i];
        prev[prox[i]] = prev[i];
        

        // Confere se nenhuma orelha nova se formou
        i = prox[i];
        orelha[i] = eDiagonal (p, prev[i], prox[i]);
        i = prev[i];
        orelha[i] = eDiagonal (p, prev[i], prox[i]);
    }

    free (orelha); free (prev); free (prox);
    return triang;
}