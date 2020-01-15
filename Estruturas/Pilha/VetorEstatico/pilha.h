/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                                 Pilha / Stack                                       //
//                          Implementada com vetor estático                            //
//                                                                                     //
// Implementação da estrutura da pilha usando um vetor estático (não muda de tamanho). //                                             //
// Junto das operações padrão da pilha e possíveis operações diferentes que encontro   //
// por aí.                                                                             //
//                                                                                     //    
// Os valores da pilha serão abstratos (void *), pra fazer uma pilha de um tipo        //
// específico é só trocar por int por exemplo.                                         //
//                                                                                     // 
/////////////////////////////////////////////////////////////////////////////////////////

// Esse ifndef previne que o conteúdo seja definido/incluido duas vezes
#ifndef PILHA_VE_H
#define PILHA_VE_H

#include <stdlib.h> // size_t

#define FALSE 0
#define TRUE 1
typedef int bool;

// Estrutura da pilha
struct pilha {
    void *vetor; // Vetor que é a pilha
    size_t tamanho; // Tamanho em bytes dos itens da pilha
    int topo; // Índice do topo
    int max; // Tamanho máximo da pilha
};

typedef struct pilha * Pilha;

/////////////////////////////////////////////////////
//
// Funções padrão de manipulação da pilha
//
/////////////////////////////////////////////////////

// Aloca uma pilha na memória, 
// tamanho = tamanho dos elementos, max = tamanho da pilha
Pilha criaPilha (size_t tamanho, int max);

// Empilha um cópia do elemento de tamanho P->tamanho na pilha P
// Se a pilha está cheia, não faz nada
void empilha (Pilha P, void *elemento);

// Desempilha (pop) o topo de P
void desempilha (Pilha P);

// Desempilha o topo de P e retorna uma cópia do elemento desempilhado
void *desempilhaE (Pilha P);

// Retorna uma cópia do topo da pilha
void *topo (Pilha P);

// Verifica se a pilha está vazia
bool estaVazia (Pilha P);

// Verifica se a pilha está cheia
bool estaCheia (Pilha P);

// Limpa a pilha da memória
void limpa (Pilha P);

// Retorna a quantidade de elementos na pilha
int tamanho (Pilha P);

#endif
