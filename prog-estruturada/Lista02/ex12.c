#include <stdio.h>

#define MAX 80

int main() {
    char frase[MAX];
    int indice = 0;

    printf("Digite uma frase com no máximo 80 caracteres:\n");

    char c;
    while ((c = getchar()) != '\n') {   // usando getchar() e não getch() pois este programa é feito para rodar no ubuntu
        if (indice < MAX - 1) {
            frase[indice] = c;
            indice++;
        }
    }

    frase[indice] = '\0';

    printf("\nPalavras:\n");

    char *p = frase;
    while (*p != '\0') {

        while (*p == ' ')
            p++;

        while (*p != ' ' && *p != '\0') {
            printf("%c", *p);
            p++;
        }

        printf("\n");
    }

    return 0;
}