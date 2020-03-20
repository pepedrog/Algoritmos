/////////////////////////////////////////////////////////////////////////
//                                                                     //
//                 Algoritmo de Shamos e Hoey (1985)                   //
//                                                                     //
// Problema: Dados n pontos no plano, determinar dois deles que estão  //
// a distância mínima (par de pontos mais próximos).                   //
//                                                                     //
// Um primeiro algoritmo seria testar todos os pares de pontos, consu- //
// mindo tempo O(n^2).                                                 //
// O algoritmo de Shamos e Hoey usa a técnica de divisão e conquista   //
// e consegue resolver o problema em tempo O(n lgn).                   //
// Ele se baseia na seguinte ideia:                                    //
//                                                                     //
// Shamos-Hoey(X, Y, n):                                               //
//     Pré ordena os pontos pela coordenada X.                         //
//     Divide os pontos em 2 metades                                   //
//     Resolve recursivamente o problema para as duas metades          //
//     * Encontra um par de pontos que usa um ponto de cada metade tal //
//     que a distância entre esses pontos seja mínima.                 //
//     A resposta é o mínimo entre o par da esquerda, da direita e o   //
//     que usa um ponto de cada.                                       //
//                                                                     //
// * Esse passo é o mais complexo, pois tem que ser feito em O(n).     //
// Com esses passos, o tempo do algoritmo pode ser dado pela fórmula   //
// T(n) = 2*T(n/2) + O(n) e isso é O(n lgn). 
//                                                                     //
// Esse algoritmo aparece na sessão 33.4 do enciclopédico CLRS.        //
// Shamos e Preparata mostram que esse algoritmo é ótimo.              //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

// Compilar com

// Ou implementar o mergesort aqui

#include "../Ordenação/vetor.h" // mergeSort
#include "geometria.h"
#include <stdlib.h>
#include <stdio.h>

// Função que retorna a distância entre dois pontos ou infinito se a distância for a 0
float dist (ponto p1, ponto p2) {
    float d = dist2 (p1, p2);
    if (d > 0) return d;
    return __FLT_MAX__;
}

// Função que retorna o par com menor distância
par minPar (par par1, par par2) {
    if (dist (par1.p1, par1.p2) < dist (par2.p1, par2.p2)) return par1;
    return par2;
}

// Função que passaremos para ordenar, verifica qual ponto tem a coord x menor
int comparaX (const void *p1, const void *p2) {
    if (((ponto *) p1)->x > ((ponto *) p2)->x)
        return 1;
    return -1;
}

// macro para o valor absoluto de x
#define abs(x) ((x) > 0 ? (x) : -(x))

// Função que recebe um vetor de ponto P[i..j] ordenados pela coordenada Y
// e retorna um vetor de pontos que estão a uma faixa vertical de tamanho d do ponto meio
// ou seja, pontos com a coordenada x entre [meio.x - d, meio.x + d]
// O tamanho do vetor retornado estará em nCand
ponto *candidatos (ponto *P, int i, int j, ponto meio, float d, int *nCand) {
    *nCand = 0;
    ponto *cand = malloc ((j - i) * sizeof (ponto));
    for (int k = i; k < j; k++)
        if (abs(P[k].x - meio.x) < d)
            cand[(*nCand)++] = P[k];
    return cand;
}

// Função que recebe um vetor de pontos P[i..j] ordenados pela coordenada Y e
// divididos em duas metades pelo ponto meio e retorna um par de pontos com um ponto
// de cada metade com distância mínima.
par pontosInter (ponto *P, int i, int j, ponto meio, par min) {
    int k, l;
    float dCand, d = dist (min.p1, min.p2);
    // Vamos achar todos os pontos na faixa ]-d, d[
    // Que são candidatos a serem um par próximo
    int nCand; // número de candidatos
    ponto *cand = candidatos (P, i, j, meio, d, &nCand);
    // Pra cada candidato, confiro se tem algum par de pontos proximos
    for (k = 0; k < nCand; k++) {
        for (l = k + 1; l < nCand; l++) {
            // Se os pontos já estão distantes, posso parar de olhar
            if (cand[l].y - cand[k].y > d) break;
            // (O que garante que essa função é linear é que nunca há mais que 7 candidatos
            // Então esse for interno não repetirá mais que 7 vezes)

            dCand = dist (cand[k], cand[l]);
            if (dCand < d) {
                d = dCand;
                min.p1 = cand[k];
                min.p2 = cand[l];
            }
        }
    }
    free (cand);
    return min;
}

// Função intercala do mergeSort que ordenará os pontos pela coordenada Y
void intercalaY (ponto *P, int ini, int fim) {
    ponto *aux = malloc ((fim - ini) * sizeof (ponto));
    int meio = (ini + fim) / 2;
    int ini1 = ini;
    int ini2 = meio;
    int atual = 0;
    // Enquanto nenhuma das duas metades acabar
    while (ini1 < meio && ini2 < fim) {
        if (P[ini1].y > P[ini2].y) aux[atual++] = P[ini2++];
        else aux[atual++] = P[ini1++];
    }
    // Copia a metade que ainda não acabou pro final do vetor
    while (ini1 < meio) aux[atual++] = P[ini1++];
    while (ini2 < fim) aux[atual++] = P[ini2++];
    // Copia o aux no vetor
    atual = 0;
    while (ini < fim) P[ini++] = aux[atual++];
    free (aux);
}

// Encontra o par de pontos mais próximo entre os pontos i e j.
// Enquanto isso ordena o vetor P em relação a coordenada Y (mergesort escondido)
par pontosProximosRec (ponto *P, int i, int j) {
    par min;
    // Base da recorrência, quando 2 ou 1 ponto
    if (j - i <= 2) {
        min.p1 = P[i];
        min.p2 = P[j-1];
        // Ordena com relação a Y (base do mergesort escondido)
        if (P[i].y > P[j-1].y) { 
            ponto aux = P[i];
            P[i] = P[j-1];
            P[j-1] = aux;
        }
    }
    else {
        int q = (i + j)/2;
        ponto meio = P[q];
        // Calculamos o menor par das duas metades
        par esq = pontosProximosRec (P, i, q);
        par dir = pontosProximosRec (P, q, j);
        min = minPar (esq, dir);
        // Na recursão, ordena os pontos pela coordenada Y (mergeSort)
        intercalaY (P, i, j);
        // Calculamos o menor par entre as duas metades
        par inter = pontosInter (P, i, j, meio, min);
        min = minPar (min, inter); 
    }
    return min;
}

// Função que recebe um vetor de pontos P[1..n]
// E retorna um par de pontos que estão a distância mínima
par pontosProximos (ponto *P, int n) {
    mergeSort ((void *) P, n, sizeof (ponto), comparaX);
    // Imprimir os pontos para debugar
    // for (int i = 0; i < n; i++) 
    //    printf ("(%.3f, %.3f)\n", P[i].x, P[i].y);
    return pontosProximosRec (P, 0, n);
}