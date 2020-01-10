/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                                 Pilha / Stack                                       //
//                        Implementada com tabelas dinâmicas                           //
//                                                                                     //
// Implementação da estrutura da pilha usando um vetor dinâmico (muda de tamanho).     // 
// Ele dobra de tamanho quando fica cheio e reduz quando fica muito vazio.             //
// Junto das operações padrão da pilha e possíveis operações diferente que encontro    //
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
    size_t tam_elemento; // Tamanho em bytes dos itens da pilha
    int topo; // Índice do topo
    int tamanho; // Tamanho atual da pilha
};

typedef struct pilha * Pilha;

/////////////////////////////////////////////////////
//
// Funções padrão de manipulação da pilha
//
/////////////////////////////////////////////////////

// Aloca uma pilha na memória, tamanho = tamanho dos elementos
Pilha criaPilha (size_t tam_elemento);

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

// Limpa a pilha da memória
void limpa (Pilha P);

// Retorna a quantidade de elementos na pilha
int tamanho (Pilha P);

#endif
