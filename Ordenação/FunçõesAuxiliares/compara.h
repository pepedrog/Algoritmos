///////////////////////////////////////////////////////////////////////////////
//
// Funções abstratas de comparação, para facilitar a ordenação genérica
// -se a > b, retorna positivo
// -se a == b, retorna 0
// -se a < b, retorna negativo
//
///////////////////////////////////////////////////////////////////////////////

int INTcompara (const void *a, const void *b);

int FLOATcompara (const void *a, const void *b);

int DOUBLEcompara (const void *a, const void *b);

int CHARcompara (const void *a, const void *b);
/*
int STRINGcompara (const void *a, const void *b);
*/
