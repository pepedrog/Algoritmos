/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                      Ordenação por Flutuação bidirecionada                          //
//                               "Ordenação Coquetel"                                  //
//                   (Bubble Sort bidirecionado / Cocktail Sort)                       //
//                                                                                     //
// Algoritmo de ordenação baseado na seguinte ideia:                                   //
// - Empurrar algum elemento pro final do vetor até que ele esbarre em alguem maior    //
// - Depois, parar de empurrar esse elemento e empurrar o elemento maior               //
// - Repetir esse processo até 'flutuar' o maior pro final do vetor                    //
// - Fazer essa flutuação na direção contrária, flutuando o menor pro começo do vetor  //
// - Repetir até que todos os elementos já tenham flutuado pro seu devido lugar        //
//                                                                                     //
// É um algoritmo de ordenação estável e consome tempo O(n^2) no caso medio e          //
// O(n) no melhor caso (vetor já ordenado ou quase).                                   //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

#include "FunçõesAuxiliares/compara.h" // Funções de comparação pros tipos primitivos
#include "vetor.h" // Definição do vetor e troca()

#define v(i) ((char *) v + (i) * sz)

// Ordena o vetor v com a ordem estabelecida pela função compara
void cocktailSort (vetor v, int n, size_t sz, int (*compara) (const void *, const void *)) {
    int fim = n, ini = 1;
    while (ini < fim) {
        // Vai flutuando do começo pro fim
        for (int i = ini; i < fim; i++)
            if (compara (v(i - 1), v(i)) > 0)
                troca (v, i - 1, i, sz);
        fim--;
        // Vai flutuando do fim pro começo
        for (int i = fim - 1; i >= ini; i--)
            if (compara (v(i - 1), v(i)) > 0)
                troca (v, i - 1, i, sz);
        ini++;
    }
}