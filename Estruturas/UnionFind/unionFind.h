/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                                 Union Find                                          //
//                                                                                     //
// Union Find corresponde á duas operações que permitem trabalhar com elementos de     //
// conjuntos disjuntos. Onde unimos conjuntos e descobrimos a qual conjunto um dado    // 
// elemento pertence.                                                                  //
//                                                                                     //
// É uma estrutura muito útil em aplicações com grafos, quando temos que decidir se    //
// dois vértices pertencem a determinados conjuntos.                                   //
//                                                                                     //
// Para um mais de detalhes de cada implementação, conferir o arquivo .c de cada uma.  //
// Cada uma tem um pósfixo nas funções para evitar conflitos.                          //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef UF_H
#define UF_H

/////////////////////////////////////////////////////////////////////////////////////////
//                                 Quick Find                                          //
/////////////////////////////////////////////////////////////////////////////////////////

// Estrutura do Union Find para o QF
struct qf {
    int *id; // Vetor de ids
    int n;   // Quantidade de elementos
};

typedef struct qf *QF;

// Aloca um UF na memória e inicializa com n conjuntos unitários
QF criaQF (int n);

// Devolve o identificador do conjunto do elemento i no Union Find UF
int findQF (QF UF, int i);

// Conecta os elementos i e j no UnionFind UF
void unionQF (QF UF, int i, int j);

/////////////////////////////////////////////////////////////////////////////////////////
//                                 Quick Union                                         //
/////////////////////////////////////////////////////////////////////////////////////////

// Estrutura do Union Find para o QU
struct qu {
    int *id; // Vetor de ids
    int n;   // Quantidade de elementos
};

typedef struct qu *QU;

// Aloca um UF na memória e inicializa com n conjuntos unitários
QU criaQU (int n);

// Devolve o identificador do conjunto do elemento i no Union Find UF
int findQU (QU UF, int i);

// Conecta os elementos i e j no UnionFind UF
void unionQU (QU UF, int i, int j);

/////////////////////////////////////////////////////////////////////////////////////////
//                             Weighted Quick Union                                    //
/////////////////////////////////////////////////////////////////////////////////////////

// Estrutura do Union Find para o QU
struct wqu {
    int *id; // Vetor de ids
    int *sz; // Vetor de tamanho dos conjuntos
    int n;   // Quantidade de elementos
};

typedef struct wqu *WQU;

// Aloca um UF na memória e inicializa com n conjuntos unitários
WQU criaWQU (int n);

// Devolve o identificador do conjunto do elemento i no Union Find UF
int findWQU (WQU UF, int i);

// Conecta os elementos i e j no UnionFind UF
void unionWQU (WQU UF, int i, int j);

/////////////////////////////////////////////////////////////////////////////////////////
//                          Weighted Quick Union (height)                              //
/////////////////////////////////////////////////////////////////////////////////////////

// Estrutura do Union Find para o QU
struct hqu {
    int *id; // Vetor de ids
    int *h; // Vetor com a altura dos conjuntos
    int n;   // Quantidade de elementos
};

typedef struct hqu *HQU;

// Aloca um UF na memória e inicializa com n conjuntos unitários
HQU criaHQU (int n);

// Devolve o identificador do conjunto do elemento i no Union Find UF
int findHQU (HQU UF, int i);

// Conecta os elementos i e j no UnionFind UF
void unionHQU (HQU UF, int i, int j);

/////////////////////////////////////////////////////////////////////////////////////////
//                 Weighted Quick Union com Path Compression by Harving                //
/////////////////////////////////////////////////////////////////////////////////////////

// Estrutura do Union Find para o QU
struct qupch {
    int *id; // Vetor de ids
    int *sz; // Vetor de tamanho dos conjuntos
    int n;   // Quantidade de elementos
};

typedef struct qupch *QUPCH;

// Aloca um UF na memória e inicializa com n conjuntos unitários
QUPCH criaQUPCH (int n);

// Devolve o identificador do conjunto do elemento i no Union Find UF
int findQUPCH (QUPCH UF, int i);

// Conecta os elementos i e j no UnionFind UF
void unionQUPCH (QUPCH UF, int i, int j);

/////////////////////////////////////////////////////////////////////////////////////////
//                 Weighted Quick Union com Path Compression by Harving                //
/////////////////////////////////////////////////////////////////////////////////////////

// Estrutura do Union Find para o QU
struct quph {
    int *id; // Vetor de ids
    int *sz; // Vetor de tamanho dos conjuntos
    int n;   // Quantidade de elementos
};

typedef struct quph *QUPH;

// Aloca um UF na memória e inicializa com n conjuntos unitários
QUPH criaQUPH (int n);

// Devolve o identificador do conjunto do elemento i no Union Find UF
int findQUPH (QUPH UF, int i);

// Conecta os elementos i e j no UnionFind UF
void unionQUPH (QUPH UF, int i, int j);

/////////////////////////////////////////////////////////////////////////////////////////
//                Weighted Quick Union com Path Compression by Splitting               //
/////////////////////////////////////////////////////////////////////////////////////////

// Estrutura do Union Find para o QU
struct qups {
    int *id; // Vetor de ids
    int *sz; // Vetor de tamanho dos conjuntos
    int n;   // Quantidade de elementos
};

typedef struct qups *QUPS;

// Aloca um UF na memória e inicializa com n conjuntos unitários
QUPS criaQUPS (int n);

// Devolve o identificador do conjunto do elemento i no Union Find UF
int findQUPS (QUPS UF, int i);

// Conecta os elementos i e j no UnionFind UF
void unionQUPS (QUPS UF, int i, int j);

/////////////////////////////////////////////////////////////////////////////////////////
//                   Weighted Quick Union com Path Compression Completa                //
/////////////////////////////////////////////////////////////////////////////////////////

// Estrutura do Union Find para o QU
struct qupc {
    int *id; // Vetor de ids
    int *sz; // Vetor de tamanho dos conjuntos
    int n;   // Quantidade de elementos
};

typedef struct qupc *QUPC;

// Aloca um UF na memória e inicializa com n conjuntos unitários
QUPS criaQUPC (int n);

// Devolve o identificador do conjunto do elemento i no Union Find UF
int findQUPC (QUPC UF, int i);

// Conecta os elementos i e j no UnionFind UF
void unionQUPC (QUPC UF, int i, int j);

#endif