#include <stdio.h>
#include <string.h>
#define MAX 50
int main(void) {
    char texto[MAX + 2], temp;
    int tam, i;
    gets(texto);
    tam = strlen(texto);
    for (i = 0; i < tam; i++) {  // Inicie o loop com a variável i igual a 0; repita o loop enquanto i for menor que tam; incremente i em 1 unidade a cada repetição
        temp = texto[i];  // Atribua o valor do caractere na posição i da string texto para a variável temp
        texto[i] = texto[tam - 1 - i];  //  Atribua o valor do caractere na posição tam - 1 - i da string texto para a posição i da string texto
        texto[strlen(texto) - 1 - i] = temp; // Atribua o valor da variável temp para a posição tam - 1 - i da string texto
    }
    puts(texto);
    return 0;
}
