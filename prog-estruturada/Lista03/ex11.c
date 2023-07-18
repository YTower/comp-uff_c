#include <stdio.h>

int main()
{
    char frase[21];
    int i = 0;
    char letra;
    char CARRIAGE_RETURN = '\r';
    char caracter;
    int tam = 0;

    printf("Digite uma frase: ");

    while ((letra = getch()) != CARRIAGE_RETURN && i < 20) {
        frase[i++] = letra;
        putchar(letra);
        tam++;
    }

    printf("\n\nDigite o caracter que queira remover da sua frase inteira: ");
    scanf("%c", &caracter);

    printf("\nNovaFrase: \n\n");

    for (i = 0; i < tam; i++) {
        if (frase[i] != caracter) {
            printf("%c", frase[i]);
        }
    }

    printf("\n\n");
}
