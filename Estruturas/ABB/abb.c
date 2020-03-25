/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
// Implementação das funções de manipulação da ABB, definidas em abb.h                 //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "abb.h"

// Função que aloca uma ABB na memória com a função compara
Abb criaAbb (int (*compara) (const void *, const void *)) {
    Abb nova = malloc (sizeof (struct abb));
    nova->n = 0;
    nova->raiz = NULL;
    nova->compara = compara;
    return nova;
}

// Aloca um novo nó na memória e copia esses valores
No novoNo (void *chave, size_t sz_chave, void *valor, size_t sz_valor, No esq, No dir) {
    No novo = malloc (sizeof (struct no));
    novo->sz_chave = sz_chave;
    novo->sz_valor = sz_valor;
    novo->esq = esq;
    novo->dir = dir;
    novo->chave = malloc (sizeof (sz_valor));
    novo->valor = malloc (sizeof (sz_chave));
    while (sz_chave--)
        ((char *) novo->chave)[sz_chave] = ((char *) chave)[sz_chave];
    while (sz_valor--)
        ((char *) novo->valor)[sz_valor] = ((char *) chave)[sz_valor];
    return novo;
}

// Limpa um Nó da memória
void freeNo (No limpado) {
    free (limpado->valor);
    free (limpado->chave);
    free (limpado);
}

// Função que insere um novo nó {chave, valor} na arvore (criando uma copia da chave e valor)
void insere (Abb arvore, void *chave, size_t sz_chave, void *valor, size_t sz_valor) {
    // Cria o nó
    No novo = novoNo (chave, sz_chave, valor, sz_valor, NULL, NULL);
    // Faz a busca na árvore
    No atual = arvore->raiz;
    while (atual != NULL) {
        int cmp = arvore->compara (chave, atual->chave);
        if (cmp > 0)
            atual = atual->dir;
        else if (cmp < 0)
            atual = atual->esq;
        else 
            // se já tem um nó com essa chave, limpa ele para atualizar
            freeNo (atual);
    }
    atual = novo;
}

// Função que remove o nó associado a chave
void remove (Abb arvore, void *chave) {
    // Faz a busca na árvore e da um free ao achar
    No atual = arvore->raiz;
    while (atual != NULL) {
        int cmp = arvore->compara (chave, atual->chave);
        if (cmp > 0)
            atual = atual->dir;
        else if (cmp < 0)
            atual = atual->esq;
        else
            freeNo (atual);
    }
}

// Função que busca um nó associdado a chave e retorna o nó correspondente ou NULL
// se não houver nenhum nó
No busca (Abb arvore, void *chave) {
    // Faz a busca na árvore
    No atual = arvore->raiz;
    while (atual != NULL) {
        int cmp = arvore->compara (chave, atual->chave);
        if (cmp > 0)
            atual = atual->dir;
        else if (cmp < 0)
            atual = atual->esq;
        // achei o nó
        else  break;
    }
    return atual;
}

int alturaRec (No raiz, int h) {
    if (raiz == NULL) return h;
    int h_esq = alturaRec (raiz->esq, h + 1);
    int h_dir = alturaRec (raiz->dir, h + 1);
    if (h_esq > h_dir) return h_esq;
    return h_dir;
}

// Função que retorna a altura da arvore
int altura (Abb arvore) {
    return alturaRec (arvore->raiz, 0);
}

// Função que retorna a quantidade de nós na árvore
int nos (Abb arvore) {
    return arvore->n;
}