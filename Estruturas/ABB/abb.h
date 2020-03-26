/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                           Árvore Binária de Busca (ABB)                             //
//                             Binary Search Tree (BST)                                //
//                                                                                     //
// Uma Árvore Binária de Busca é uma estrutura de dados que guarda uma coleção de      //
// valores em uma dada ordem (na forma de uma tabela de símbolos). Para determinar tal //
// ordem, associamos uma chave única a cada nó e comparamos essas chaves.              //                                        //
//                                                                                     //
// Nossas chaves serão de tipos abstratos (void *) e a ordem será dada por uma função  //
// de comparação (como na função qsort da stdlib).                                     //
// O conteúdo de cada nó também será genérico, por isso precisaremos guardar o tamanho //
// da chave e do valor.                                                                //
//                                                                                     //
// Essa estrutura faz inserção, remoção e busca de valores em tempo esperado O(n lgn)  //
// e pior caso O(n), com n sendo o número de elementos.                                //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

// Esse ifndef previne que o conteúdo seja definido/incluido duas vezes
#ifndef ABB_H
#define ABB_H

#include <stdlib.h>

// Estrutura do nó da árvore
typedef struct no *No;
struct no {
    void *chave;
    void *valor;
    size_t sz_chave, sz_valor; // tamanho da chave e valor
    No esq, dir; // filhos desse nó
};

// Estrutura da Árvore
struct abb {
    int n; // Quantidade de elementos
    struct no *raiz;
    int (*compara) (const void *, const void *); // Função para comparar as chaves
};
typedef struct abb *Abb;

// Função que aloca uma ABB na memória com a função compara
Abb ABBnovaAbb (int (*compara) (const void *, const void *));

// Função que insere um novo nó {chave, valor} na arvore 
void ABBinsere (Abb arvore, void *chave, size_t sz_chave, void *valor, size_t sz_valor);

// Função que remove o nó associado a chave
void ABBremove (Abb arvore, void *chave);

// Função que busca um nó associdado a chave e retorna um ponteiro para o nó correspondente 
// ou NULL se não houver nenhum nó com essa chave
No ABBbusca (Abb arvore, void *chave);

// Função que retorna a altura da arvore
int ABBaltura (Abb arvore);

// Função que retorna a quantidade de nós na árvore
int ABBnos (Abb arvore);

// Função que limpa a árvore da memória
void ABBlimpa (Abb arvore);

// Função que percorre a árvore em pré-ordem fazendo, processando cada nó com a função processa
void ABBpreOrdem (Abb arvore, void (*processa) (No));

// Função que percorre a árvore em in-ordem fazendo, processando cada nó com a função processa
void ABBinOrdem (Abb arvore, void (*processa) (No));

// Função que percorre a árvore em pós-ordem fazendo, processando cada nó com a função processa
void ABBposOrdem (Abb arvore, void (*processa) (No));

#endif