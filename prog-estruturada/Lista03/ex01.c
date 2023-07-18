#include <stdio.h>

#define R_SIZE 5
#define S_SIZE 10
#define X_SIZE 5 // Tamanho de X igual a R

int main()
{
    int R[R_SIZE], S[S_SIZE], X[X_SIZE];
    int i, j, k, found;

    // Leia os valores de R e S
    printf("Enter %d values for R:\n", R_SIZE);
    for (i = 0; i < R_SIZE; i++) {
        scanf("%d", &R[i]);
    }
    printf("Enter %d values for S:\n", S_SIZE);
    for (i = 0; i < S_SIZE; i++) {
        scanf("%d", &S[i]);
    }

    // Encontre os elementos comuns entre R e S
    k = 0;
    for (i = 0; i < R_SIZE; i++) {
        found = 0;
        for (j = 0; j < S_SIZE; j++) {
            if (R[i] == S[j]) {
                found = 1;
                break;
            }
        }
        if (found) {
            // Verifica se o elemento já está em X
            found = 0;
            for (j = 0; j < k; j++) {
                if (R[i] == X[j]) {
                    found = 1;
                    break;
                }
            }
            // Se o elemento já não está em X, adicione ele
            if (!found) {
                X[k] = R[i];
                k++;
            }
        }
    }

    // Imprime o array
    printf("X = { ");
    for (i = 0; i < k; i++) {
        printf("%d ", X[i]);
    }
    printf("}\n");

    return 0;
}
