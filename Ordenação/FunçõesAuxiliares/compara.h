///////////////////////////////////////////////////////////////////////////////
//
// Funções abstratas de comparação, para facilitar a ordenação genérica
// -se a > b, retorna positivo
// -se a == b, retorna 0
// -se a < b, retorna negativo
//
///////////////////////////////////////////////////////////////////////////////

int int_compara (const void *a, const void *b);

int float_compara (const void *a, const void *b);

int double_compara (const void *a, const void *b);

int char_compara (const void *a, const void *b);
/*
int STRINGcompara (const void *a, const void *b);
*/
