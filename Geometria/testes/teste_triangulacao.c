#include "../geometria.h"
#include <stdio.h>

int main () {
    // Testar triangular um pentagonozinho convexo amigo
    poligono pentagono;
    ponto vertices[5] = { novoPonto (0,0), novoPonto (1,0), novoPonto (2, 1),
                          novoPonto (1,2), novoPonto (0,1) };
    pentagono = novoPoligono (5, vertices);
    diagonal *triang = triangulacao2 (pentagono);
    for (int i = 0; i < 2; i++)
        printf ("Diagonal %d: (%d, %d)\n", i, triang[i].i, triang[i].j);
    printf("----------------\n");
    // Agora com um polígono mais afiado (um formato de t)
    poligono t;
    ponto vt[8] = { novoPonto (1, 0), novoPonto (2,0), novoPonto (2,1), novoPonto (3,1),
                    novoPonto (3, 2), novoPonto (0,2), novoPonto (0,1), novoPonto (1,1) };
    
    t = novoPoligono (8, vt);
    diagonal *triang2 = triangulacao2 (t);

    for (int i = 0; i < 5; i++)
        printf ("Diagonal %d: (%d, %d)\n", i, triang2[i].i, triang2[i].j);

    printf("----------------\n");
    // Agora com um polígono uma ampulheta deitada)
    poligono a;
    ponto va[6] = { novoPonto (0, 0), novoPonto (1,1.5), novoPonto (2,0), 
                    novoPonto (2,4), novoPonto (1, 2.5), novoPonto (0,4) };
    
    a = novoPoligono (6, va);
    diagonal *triang3 = triangulacao2 (a);

    for (int i = 0; i < 3; i++)
        printf ("Diagonal %d: (%d, %d)\n", i, triang3[i].i, triang3[i].j);

}