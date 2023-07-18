#include <stdio.h>

int main()
{
    char alfabeto[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    char frase[51];
    int i = 0;
    char letra;
    char CARRIAGE_RETURN = '\r';
    int tam = 0;

    printf("Digite uma frase: ");

    while ((letra = getch()) != CARRIAGE_RETURN && i < 50) {
        frase[i++] = letra;
        putchar(letra);
        tam++;
    }

    int* repetidos = (int*)calloc(26, sizeof(int));

    for (i = 0; i < tam; i++) {

        for (int j = i + 1; j < tam; j++) {
            if (frase[i] == frase[j]) {

                for (int k = 0; k < 26; k++) {
                    if (frase[i] == alfabeto[k]) {
                        repetidos[k]++;
                        frase[i] = '*';
                        break;
                    }
                }
            }
        }
    }

    for (i = 0; i < tam; i++) {
        if (repetidos[i] != 0) {
            printf("\n\nLetra: %c, Repeticoes: %d", alfabeto[i], repetidos[i] + 1);
        }
    }

    printf("\n\n");
}
