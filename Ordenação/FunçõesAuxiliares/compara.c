///////////////////////////////////////////////////////////////////////////////
//
// Funções abstratas de comparação, para facilitar a ordenação genérica
// -se a > b, retorna positivo
// -se a == b, retorna 0
// -se a < b, retorna negativo
//
// (Em geral, retornar a - b resolve)
//
///////////////////////////////////////////////////////////////////////////////

#include "compara.h"

int int_compara (const void *a, const void *b) {
    // retorna a - b
    return *((int *) a) - *((int *) b);
}

int float_compara (const void *a, const void *b) {
    // retorna a - b
    return *((float *) a) - *((float *) b);
}

int double_compara (const void *a, const void *b) {
    // retorna a - b
    return *((double *) a) - *((double *) b);
}

int char_compara (const void *a, const void *b) {
    // retorna a - b
    return *((char *) a) - *((char *) b);
}
/*
int STRINGcompara (const void *a, const void *b) {
    // retorna a - b
    return *((char *) a) - *((char *) b);
}*/