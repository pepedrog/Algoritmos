///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//                         Algoritmos de polígonos                           //
//                                                                           //
// Implementações das funções de polígonos descritas em geometria.h          //
// As definições e interface estão também nesse arquivo                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "geometria.h"

// Função que retorna se um segmento ab intersecta propriamente a borda do polígono
bool intersectaBorda (poligono p, segmento ab) {
    int k, l;
    segmento borda;
    // Testa interseção com todas as bordas kl do polígono
    for (k = 0; k < p.n; k++) {
        l = (k + 1) % p.n;
        borda.p1 = p.v[k];
        borda.p2 = p.v[l];
        if (intersectaProp (borda, ab))
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
    int u = (i - 1)%p.n, w = (i + 1)%p.n;
    segmento ui, iw; 
    ui = (segmento) {p.v[u], p.v[i]};
    iw = (segmento) {p.v[i], p.v[w]};
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

