/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                                  Fila / Queue                                       //
//                         Implementada com listas ligadas                             //
//                                                                                     //
// Implementação da estrutura da fila usando listas ligadas, aonde o início da fila é  //
// o primeiro nó.                                                                      //
//                                                                                     //
// Junto das operações padrão da fila e possíveis operações diferentes que encontro    //
// por aí.                                                                             //
//                                                                                     //    
// Os valores da fila serão abstratos (void *), pra fazer uma fila de um tipo          //
// específico é só trocar por int por exemplo. E trocar as associações de ponteiros    //
// pra atribuições normais.                                                            //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

// Esse ifndef previne que o conteúdo seja definido/incluido duas vezes
#ifndef FILA_LL_H
#define FILA_LL_H

#include <stdlib.h> // size_t

#define FALSE 0
#define TRUE 1
typedef int bool;

// Estrutura do nó da lista / fila
struct no {
    void *valor; // Conteúdo do nó
    size_t tamanho; // Tamanho em bytes do valor
    struct no *prox; // Ponteiro pro próximo nó
};

struct fila {
    struct no *primeiro; // Começo da lista ligada
    struct no *ultimo; // Ponteiro pro último elemento
    int n; // Tamanho da fila
};

// Fila como lista ligada
typedef struct fila * Fila;

/////////////////////////////////////////////////////
//
// Funções padrão de manipulação da fila
//
/////////////////////////////////////////////////////

// Aloca uma fila vazia na memória
Fila iniciaFila ();

// Insere (enqueue) o elemento de tamanho sz no final da fila P
void enfileira (Fila P, void *elemento, size_t sz);

// Remove () o elemento do inicio da fila P
void desenfileira (Fila P);

// Desenfileira o topo de P e retorna uma cópia do elemento desenfileirado
void *desenfileiraE (Fila P);

// Retorna uma cópia do elemento no início da Fila
void *inicio (Fila P);

// Verifica se a fila está vazia
bool estaVazia (Fila P);

// Limpa todos os nós da fila
void limpa (Fila P);

// Retorna a quantidade de elementos na fila
int tamanho (Fila P);

#endif