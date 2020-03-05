/////////////////////////////////////////////////////////////////////////
//                                                                     //
//                      Algoritmo de Shamos e Hoey                     //
//                                                                     //
// Problema: Dados n pontos no plano, determinar dois deles que estão  //
// a distância mínima (par de pontos mais próximos).                   //
//                                                                     //
// Um primeiro algoritmo seria testar todos os pares de pontos, consu- //
// mindo tempo O(n^2).                                                 //
// O algoritmo de Shamos e Hoey usa a técnica de divisão e conquista   //
// e consegue resolver o problema em tempo O(n lgn).                   //
// Ele se baseia na seguinte ideia:                                    //
//                                                                     //
// Shamos-Hoey(X, Y, n):                                               //
//     Pré ordena os pontos pela coordenada X.                         //
//     Divide os pontos em 2 metades                                   //
//     Resolve recursivamente o problema para as duas metades          //
//     * Encontra um par de pontos que usa um ponto de cada metade tal //
//     que a distância entre esses pontos seja mínima.                 //
//     A resposta é o mínimo entre o par da esquerda, da direita e o   //
//     que usa um ponto de cada.                                       //
//                                                                     //
// * Esse passo é o mais complexo, pois tem que ser feito em O(n).     //
/////////////////////////////////////////////////////////////////////////

// Estrutura dos nossos pontos
typedef struct {
    float x;
    float y;
} ponto;

// Estrutura que guarda um par de pontos, usaremos para retorno
typedef struct {
    Ponto p1;
    Ponto p2;
} par;

// Função que retorna o quadrado da distância de dois pontos
float dist (ponto p1, ponto p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + 
           (p1.y - p2.y)*(p1.y - p2.y);
}

// Função que retorna o par com menor distância
par minPar (par par1, par par2) {
    if (dist (par1.p1, par1.p2) < dist (par2.p1, par2.p2))
        return par1;
    return par2;
}

// Função que ordena um vetor de pontos por ordem crescente da coordenada X
// pelo algoritmo mergeSort
void ordenaX (ponto *P, int ini, int fim) {
    if (fim <= ini + 1) return;
    int meio = (ini + fim)/2;
    ordenaX (P, ini, meio);
    ordenaX (P, meio + 1, fim);
    intercalaX (P, ini, fim);
}
void intercalaX (ponto *P, int ini, int fim) {
    // to do
}


// Função que recebe um vetor de pontos P[1..n]
// E retorna um par de pontos que estão a distância mínima
par pontosProximos_SH (ponto *P, int n) {
    ordenaX (P, 1, n);
    return pontosProximosRec (P, 0, n);
}

// Encontra o par de pontos mais próximo entre os pontos i e j.
par pontosproximosRec (ponto *P, int i, int j) {
    par min;
    // Base da recorrência, quando 2 ou 1 ponto
    if (j - i <= 2) {
        min.p1 = P[i];
        min.p2 = P[j-1];
    }
    else {
        int q = (i + j)/2;
        par esq = pontosproximosRec (P, i, q);
        par dir = pontosProximosRec (P, q + 1, j);
        min = minPar (esq, dir); 
        // Calculamos agora o menor par com um ponto de cada metade
        par meio = combina (P, i, j, min); // to do
        min = minPar (min, meio); 
    }
    return min;
}