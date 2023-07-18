#include <stdio.h>

#define LINHAS 8
#define COLUNAS 8

void count_pcs(int tab[LINHAS][COLUNAS], int* qtd, int* soma_p, int* soma_b, int* aus_pcs) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            int peca = tab[i][j];
            qtd[peca]++;
            if (peca == 1 || peca == 2) {
                *soma_p += peca;
            } else if (peca == 4 || peca == 6) {
                *soma_b += peca;
            } else if (peca == 0) {
                (*aus_pcs)++;
            }
        }
    }
}

int main() {
    int tab[LINHAS][COLUNAS] = {
        {1, 3, 0, 5, 4, 0, 2, 1},
        {1, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 6, 0},
        {1, 0, 0, 1, 1, 0, 0, 1},
        {0, 1, 0, 4, 0, 0, 1, 0},
        {0, 0, 3, 1, 0, 0, 1, 1},
        {1, 0, 6, 6, 0, 0, 1, 0},
        {1, 0, 5, 0, 1, 1, 0, 6}
    };

    int qtd[7] = {0};
    int soma_p = 0;
    int soma_b = 0;
    int aus_pcs = 0;

    count_pcs(tab, qtd, &soma_p, &soma_b, &aus_pcs);

    printf("Soma peões e bispos: %d\n", soma_p + soma_b);
    printf("Posições com ausência de peças: %d\n", aus_pcs);
    printf("Quantidade de peões: %d\n", qtd[1]);
    printf("Quantidade de cavalos: %d\n", qtd[2]);
    printf("Quantidade de torres: %d\n", qtd[3]);
    printf("Quantidade de bispos: %d\n", qtd[4]);
    printf("Quantidade de reis: %d\n", qtd[5]);
    printf("Quantidade de rainhas: %d\n", qtd[6]);

    return 0;
}
