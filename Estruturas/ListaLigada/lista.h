/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                            Lista Ligada / Linked List                               //
//                                                                                     //
// Lista Ligada é uma estrutura de dados que guarda uma coleção de itens, onde cada    //
// itens guarda um ponteiro para conseguir acessar o próximo.                          //
//                                                                                     //
// A convenção que usarei aqui é que a lista acaba em um nó nulo.                      //
//                                                                                     //
// Os valores da lista serão abstratos (void *), pra fazer uma lista de um tipo        //
// específico é só trocar por int por exemplo.                                         //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

// Esse ifndef previne que o conteúdo seja definido/incluido duas vezes
#ifndef LL_H
#define LL_H

#include <stdlib.h> // size_t

#define FALSE 0
#define TRUE 1
typedef int bool;

// Estrutura do nó da lista
struct no {
    void *valor; // Conteúdo do nó
    size_t tamanho; // Tamanho em bytes do valor
    struct no *prox; // Ponteiro pro próximo nó
};
typedef struct no *No;

/////////////////////////////////////////////////////
//
// Funções padrão de manipulação da lista
//
/////////////////////////////////////////////////////

// Insere um elemento de tamanho sz no começo da lista
void insere (No *lista, void *elemento, size_t sz);

// Insere um elemento de tamanho sz no final da lista
void insereFim (No *lista, void *elemento, size_t sz);

// Versão do insere que retorna um ponteiro para a nova lista
No insereP (No lista, void *elemento, size_t sz);

// Recebe uma lista ordenada e insere o elemento mantendo a ordem estabelecida pela função compara
void insereOrdenado (No *lista, void *elemento, size_t sz, int (*compara)(void *, void *));

// Remove a primeira aparição do elemento na lista
void removeL (No *lista, void *elemento, size_t sz);

// Busca o elemento na lista e retorna o nó que o elemento está ou NULL se ele não está
No busca (No lista, void *elemento, size_t sz);

// Verifica se a lista está vazia
bool estaVazia (No lista);

// Limpa todos os nós da lista
void limpa (No *lista);

// Retorna a quantidade de elementos na lista
int tamanho (No lista);

#endif
