#include <stdio.h>
#include <stdbool.h>

#define TAM 3

bool verifica_soma(int matriz[TAM][TAM]) {
    int soma_primeira_linha = 0;
  

    for (int j = 0; j < TAM; j++) {
        soma_primeira_linha += matriz[0][j];
    }
  

    for (int i = 1; i < TAM; i++) {
        int soma_linha = 0;
      

        for (int j = 0; j < TAM; j++) {
            soma_linha += matriz[i][j];
        }
      

        if (soma_linha != soma_primeira_linha) {
            return false;
        }
    }
  
    return true;
}

int main() {
    int matriz[TAM][TAM] = 	 {{2, 4, 6},
                              {1, 3, 5},
                              {7, 8, 9}};

    bool res = verifica_soma(matriz);

    if (res)
        printf("A soma de cada linha totaliza o mesmo valor.\n");
    else
        printf("A soma de cada linha não totaliza o mesmo valor.\n");


    return 0;
}
