/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                                 Pilha / Stack                                       //
//                          Implementada com listas ligadas                            //
//                                                                                     //
// Implementação da estrutura da pilha usando listas ligadas (implementação padrão),   // 
// aonde o topo da pilha é o primeiro nó.                                              //
// Junto das operações padrão da pilha e possíveis operações diferente que encontro    //
// por aí.                                                                             //
//                                                                                     //    
// Os valores da pilha serão abstratos (void *), pra fazer uma pilha de um tipo        //
// específico é só trocar por int por exemplo.                                         //
//                                                                                     // 
/////////////////////////////////////////////////////////////////////////////////////////

// Esse ifndef previne que o conteúdo seja definido/incluido duas vezes
#ifndef PILHA_H
#define PILHA_H

#include <stdlib.h> // size_t

#define FALSE 0
#define TRUE 1
typedef int bool;

// Estrutura do nó da lista / pilha
struct no {
    void *valor; // Conteúdo do nó
    struct no *prox; // Ponteiro pro próximo nó
};

// Pilha como lista ligada
typedef struct no * Pilha;

/////////////////////////////////////////////////////
//
// Funções padrão de manipulação da pilha
//
/////////////////////////////////////////////////////

// Empilha (push) na pilha P um elemento de tamanho sz
void empilha (Pilha P, void *elemento, size_t sz);

// Desempilha (pop) e retorna o elemento do topo de P
void *desempilha (Pilha P);

// Verifica de a pilha está vazia
bool estaVazia (Pilha P);

// Limpa todos os nós da pilha
void limpa (Pilha P);

#endif