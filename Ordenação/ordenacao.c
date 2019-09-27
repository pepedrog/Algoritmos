#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Troca o conteúdo (t bytes) de dois endereços de memória
void troca( void* a, void* b, size_t t) {
    void * aux = malloc( t);
    memcpy( aux, a, t);
    memcpy( a, b, t);
    memcpy( b, aux, t);
}

void INTprintaVetor( int *v, int n) {
    for( int i = 0; i < n; i++) printf( "%d\t", v[i]);
    puts("\n");
}

// Selection Sort -> Ordenação por inserção
void INTselectionSort( int* v, int n) {
    int i, min, j;
    // Percorre o vetor
    for( i = 0; i < n; i++) {
        min = i;
        // Percorre a parte não ordenada procurando o menor elemento
        for( j = i; j < n; j++)
            if( v[j] < v[min]) min = j;
        // Coloca o menor elemento na parte ordenada
        troca( &v[i], &v[min], sizeof( int));     
    }
}

int main( int argc, char* argv[]) {
    int v[10] = { 10, 3, 5, 10, 25, 35, 7, 2, 5, 1};
    INTprintaVetor( v, 10);
    INTselectionSort( v, 10);
    INTprintaVetor( v, 10);

}