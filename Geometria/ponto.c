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

// Função que calcula o dobro da área do triângulo dado por p1, p2 e p3
// Se os pontos estão em sentido anti-horário, a responta será positiva,
// Se estiverem em sentido horário, será negativa.
float area2 (ponto p1, ponto p2, ponto p3) {
    // Esse cálculo é o resultado do determinante
    // | x1 y1 1 |
    // | x2 y2 1 |
    // | x3 y3 1 | para calcular área do triângulo
    return (p1.x - p3.x)*(p2.y - p3.y) -
           (p1.y - p3.y)*(p2.x - p3.x);
}

///////////////////////////////////////////////////////////////////////////////
// Predicados Geométricos
///////////////////////////////////////////////////////////////////////////////

// Função que retorna se os pontos a, b, c são colineares
bool colineares (ponto a, ponto b, ponto c) {
    // São colineares se a àrea do triangulo é 0
    // Mas temos que tomar cuidado com erros numéricos
    float area = Area2 (a, b, c);
    return (area <= 2*__FLT_EPSILON__ && area >= 2*__FLT_EPSILON__);
}

// Função que retorna se o ponto c está estritamente à esquerda do segmento ab
bool esquerdaEstrita (segmento ab, ponto c) {
    return (esquerda (ab, c) && !colineares (ab.p1, ab.p2, c));
}

// Função que retorna se o ponto c está à esquerda ou é colinear ao segmento ab
bool esquerda (segmento ab, ponto c) {
    return Area2 (ab.p1, ab.p2, c) >= 0;
}

// Função que retorna se o ponto c está estritamente à direita do segmento ab
bool direitaEstrita (segmento ab, ponto c) {
    return (direita (ab, c) && !colineares (ab.p1, ab.p2, c));
}

// Função que retorna se o ponto c está à direita ou é colinear ao segmento ab
bool direita (segmento ab, ponto c) {
    return Area2 (ab.p1, ab.p2, c) <= 0;
}

// Função que retorna se o ponto c pertence ao segmento ab
bool entre (segmento ab, ponto c) {
    if (!colineares (ab.p1, ab.p2, c)) return false;
    if (ab.p1.x != ab.p1.y)
        return ((ab.p1.x <= c.x && c.x <= ab.p2.x) || (ab.p2.x <= c.x && c.x <= ab.p1.x));
    return ((ab.p1.y <= c.y && c.y <= ab.p2.y) || (ab.p2.y <= c.y && c.y <= ab.p1.y));
}

// Função que retorna se o segmento ab e o segmento cd se intersectam em um ponto
// no interior deles (não considera as extremidades)
bool intersectaProp (segmento ab, segmento cd) {
    // Se intersecta e as extremidades não são colineares
    return (intersecta (ab, cd) && (!colineares (ab.p1, ab.p2, cd.p1) ||
                                    !colineares (ab.p1, ab.p2, cd.p2) ||
                                    !colineares (cd.p1, cd.p2, ab.p1) ||
                                    !colineares (cd.p1, cd.p2, ab.p2) ));
}

// Função que retorna se o segmento ab e o segmento cd se intersectam
bool intersecta (segmento ab, segmento cd) {
    // Esse grande predicado faz mais sentido se você visualizar os pontos num papel

    // Os pontos de um segmento tem que estar um de cada lado do outro segmento
    return ((( esquerda (ab, cd.p1) &&  direita (ab, cd.p2)) ||
             (  direita (ab, cd.p1) && esquerda (ab, cd.p2))) &&
            (( esquerda (cd, ab.p1) &&  direita (cd, ab.p2)) ||
             (  direita (cd, ab.p1) && esquerda (cd, ab.p2))));
}
