///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Implementação das funções mais simples de manipulação de pontos.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////[

#include "geometria.h"

// Função para facilitar a inicialização de um ponto
ponto novoPonto (float x, float y) {
    return (ponto) {x, y};
}

// Função que retorna o quadrado distância euclidiana entre os pontos p1 e p2
float dist2 (ponto p1, ponto p2) {
    return ((p1.x - p2.x)*(p1.x - p2.x) + 
            (p1.y - p2.y)*(p1.y - p2.y));
}
