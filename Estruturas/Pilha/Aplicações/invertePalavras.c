//////////////////////////////////////////////////////////////////
//                                                              //
//                      Inverte Palavras                        //
//                                                              //
// Exercício 3 das notas de aula do professor Paulo Feofillof   //
// https://www.ime.usp.br/~pf/algoritmos/aulas/pilhas.html      //
//                                                              //
// Escreva um algoritmo que use uma pilha para inverter a ordem //
// das letras de cada palavra de uma string, preservando a      //
// ordem das palavras.                                          //
// Por exemplo, para a string  ESTE EXERCICIO E MUITO FACIL     //
// o resultado deve ser  ETSE OICICREXE E OTIUM LICAF.          //
//                                                              //
// O programa lerá da entrada padrão um inteiro n e depois uma  // 
// string de n palavras separadas por espaços.                  //
//                                                              //
////////////////////////////////////////////////////////////////// 

// Para compilar: gcc -o invertePalavras invertePalavras.c ../ListaLigada/pilha.c

// Vamos usar a pilha com lista ligada, podia ser qualquer uma
#include "../ListaLigada/pilha.h"
#include <stdio.h>
#include <ctype.h> // isalnum()

int main () {
    int n;
    char *letra;
    Pilha P = NULL;
    scanf ("%d", &n);
    // Enquanto tem palavra pra ler
    while (n) {
        scanf ("%c", letra);
        // Se for letra empilha
        if (isalnum (*letra))
            empilha (&P, letra, 1);
        // Se não for, desempilha a palavra
        else if (*letra == ' ' || *letra == '.') {
            while (!estaVazia (P)) {
                letra = desempilhaE (&P);
                printf ("%c", *letra);
            }
            if (n > 1) printf (" ");
            n--;
        }
    }
    printf (".");
    return 0;
}