/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                                  Fila / Queue                                       //
//                        Implementada com tabelas dinâmicas                           //
//                                                                                     //
// A fila é uma ADT (Abstract Data Type) que funciona como a fila da vida real.        //
// Os primeiros a entrar são os primeiros a sair (ordem FIFO).                         //
//                                                                                     //
// Implementação da estrutura é feita usando um vetor dinâmico (muda de tamanho).      //
// Em java isso é o ArrayList, em c++ é o vector.                                      //
// Junto das operações padrão da fila e possíveis operações diferentes que encontro    //
// por aí.                                                                             //
//                                                                                     //    
// Os valores da fila serão abstratos (void *), pra fazer uma fila de um tipo          //
// específico é só trocar por int por exemplo.                                         //
//                                                                                     // 
/////////////////////////////////////////////////////////////////////////////////////////

// Esse ifndef previne que o conteúdo seja definido/incluido duas vezes
#ifndef Fila_VE_H
#define Fila_VE_H

#include <stdlib.h> // size_t

#define FALSE 0
#define TRUE 1
typedef int bool;

// Estrutura da fila
struct fila {
    void *vetor; // Vetor que é a fila
    size_t tam_elemento; // Tamanho em bytes dos itens da fila
    int ini; // Índice do começo da fila
    int fim; // Índice do final da fila
    int tamanho; // Tamanho atual da fila (que vai mudando)
};

typedef struct fila * Fila;

/////////////////////////////////////////////////////
//
// Funções padrão de manipulação da fila
//
/////////////////////////////////////////////////////

// Aloca uma Fila na memória, 
// tamanho = tamanho dos elementos
Fila criaFila (size_t tamanho);

// EmFila um cópia do elemento de tamanho P->tamanho na Fila P
// Se a Fila está cheia, não faz nada
void enfileira (Fila F, void *elemento);

// DesemFila (pop) o topo de P
void desenfileira (Fila F);

// DesemFila o topo de P e retorna uma cópia do elemento desemFilado
void *desenfileiraE (Fila F);

// Retorna uma cópia do primeiro elemento da fila
void *inicio (Fila F);

// Verifica se a fila está vazia
bool estaVazia (Fila F);

// Verifica se a fila está cheia
bool estaCheia (Fila F);

// Limpa a fila da memória
void limpa (Fila F);

// Retorna a quantidade de elementos na fila
int tamanho (Fila F);

#endif
