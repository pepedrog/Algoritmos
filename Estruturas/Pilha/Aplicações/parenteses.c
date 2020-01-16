/////////////////////////////////////////////////////////////////
//                                                             //
//           Sequência de parênteses bem formada               //
//                                                             //
// Dada uma seqûencia de '(' e ')' determinar se a sequência   //
// está bem formada, ou seja, se todo abre parênteses tem um   //
// fecha parênteses na ordem certa.                            //
//                                                             //
// Exemplo:                                                    //
// "( ( ) ( ( ) ) )" - bem formada                             //
// "( ) ) ) ( ) (" - mal formada                               //
//                                                             //
// O programa lerá da entrada padrão um inteiro n e depois uma // 
// sequência de n parênteses. (o programa vai ler apenas os    //
// perênteses, tanto faz se tem espaços ou coisas entre eles). //
//                                                             //
/////////////////////////////////////////////////////////////////

// Para compilar: gcc -o parenteses parenteses.c ../VetorEstatico/pilha.c

// Vamos usar a pilha com tamanho fixo
#include "../VetorEstatico/pilha.h"
#include <stdio.h> //Scanf
int main () {
    int n;
    char parentes;
    scanf ("%d", &n);
    Pilha P = criaPilha (1, n);
    while (n--) {
        scanf ("%c", &parentes);
        if (parentes == '(')
            empilha (P, (void *) &parentes);
        else if (parentes == ')') {
            // Se a pilha está vazia então não tem parentes pra fechar
            if (estaVazia (P)) {
                printf ("Sequência de parenteses mal formada!\n");
                limpa (P);
                return 0;
            }
            else desempilha (P);
        }
        else n++;
    }
    printf ("Sequência bem formada!\n");
    limpa (P);
    return 0;

}