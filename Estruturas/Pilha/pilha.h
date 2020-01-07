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
    size_t tamanho; // Tamanho em bytes do valor
    struct no *prox; // Ponteiro pro próximo nó
};

// Pilha como lista ligada
typedef struct no * Pilha;

/////////////////////////////////////////////////////
//
// Funções padrão de manipulação da pilha
//
/////////////////////////////////////////////////////

// Empilha o elemento de tamanho sz na pilha P
void empilha (Pilha *P, void *elemento, size_t sz);

// Desempilha (pop) o topo de P
void desempilha (Pilha *P);

// Versões do empilha e desempilha (diferentes implementações)

// Empilha o elemento de tamanho sz e retorna a nova pilha
Pilha empilhaP (Pilha P, void *elemento, size_t sz);

// Desempilha o topo de P e retorna uma cópia do elemento desempilhado
void *desempilhaE (Pilha *P);

// Desempilha o elemento do topo e retorna a nova pilha
Pilha desempilhaP (Pilha P);

// Retorna uma cópia do topo da pilha
void *topo (Pilha P);

// Verifica se a pilha está vazia
bool estaVazia (Pilha P);

// Limpa todos os nós da pilha
void limpa (Pilha P);

// Retorna a quantidade de elementos na pilha
int tamanho (Pilha P);

#endif