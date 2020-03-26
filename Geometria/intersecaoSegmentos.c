/////////////////////////////////////////////////////////////////////////
//                                                                     //
//                    Algoritmo de Shamos e Hoey                       //
//               para detectar interseção de segmentos                 //
//                                                                     //
// Problema: Dados n segmentos no plano, determinar se existem dois    //
// deles que se intersectam.                                           //
//                                                                     //
// Um primeiro algoritmo seria testar todos os pares de segmentos,     //
// consumindo tempo O(n^2)                                             //
// O algoritmo de Shamos e Hoey usa a técnica de linha de varredura    //
// e consegue resolver o problema em tempo O(n lgn).                   //
// Ele se baseia na seguinte ideia:                                    //
//                                                                     //
// Shamos-Hoey(S, n):                                                  //
// - Pré-Processamento:                                                //
//     Processa os segmentos para que os pontos da esquerda sejam o p1 //
//     Coloca todos os pontos em um vetor ordenado por X,              //
//     (Guardando quais são os pontos da esquerda e direita, e a qual  //
//      segmento cada um faz parte)                                    //
// - O algoritmo                                                       //
//     - Percorre todos os pontos do vetor (linha de varredura)        //
//     - A linha de varredura (uma ABB) guardará todos os segmentos    //
//     que intersectam ela                                             //
//     - Recupera o segmento do ponto, assim como o segmento de cima e //
//     o de baixo (predecessor e sucessor na ABB)                      //
//     - Se for um ponto da esquerda:                                  //
//         Insere o segmento na linha de varredura                     //
//         Teste se tem interseção entre o sucessor e o predecessor    //
//     - Se for um ponto da direita                                    //
//         Remove o segmento da linha de varredura                     //
//         Testa se tem interseção entre o sucessor e o predecessor    //
// Se todos os testes derem falso, devolvo falso                       //
//                                                                     //
// A ideia é que as operações na linha de varredura consumam tempo lgn //
// com uma estrutura balanceada como um treap ou skip-list             //
// Para simplificar, usaremos uma ABB normal, assim nosso o consumo de //
// tempo *esperado* é O(nlgn)                                          //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

#include "geometria.h"
#include <stdlib.h>

// Nossa linha de varredura será uma ABB, vamos implementar ela com as 
// operações que precisamos:

// Estrutura do Nó da árvore
typedef struct no *No;
struct no {
    segmento s;
    No esq, dir;
};

// Função para inserir na árvore, retorna um ponteiro para a nova raiz
No insereLinha (No raiz, segmento s) {
    if (raiz == NULL) {
        No novo = malloc (sizeof (struct no));
        novo->dir = novo->esq = NULL;
        novo->s = s;
        return novo;
    }
    // Teste de esquerda: Se o p1 esta a esquerda da raiz, insiro em cima (dir)
    if (esquerda (raiz->s, s.p1))
        raiz->dir = insereLinha (raiz->dir, s);
    else raiz->esq = insereLinha (raiz->esq, s);
    return raiz;
}

// Função pra remover um segmento da linha
No removeLinha (No raiz, segmento s) {
    if (raiz == NULL) return NULL;
    // Encontrei o segmento, tem que remover
    if (raiz->s.p1 == s.p1 && raiz->s.p2 == s.p2) {
        // Remove xD
    }
    // Remove recursivo com o teste de esquerda
    if (esquerda (raiz->s, s.p1))
        raiz->dir = removeLinha (raiz->dir, s);
    else raiz->esq = removeLinha (raiz->esq, s);
    return raiz;
}

// To do: Predecessor e sucessor

// Função que recebe um vetor de n segmentos e retorna um par de segmentos que se intersectam
// ou NULL se nenhum deles se intersectarem 
segmento *intersecaoSegmentos (segmento *S, int n);