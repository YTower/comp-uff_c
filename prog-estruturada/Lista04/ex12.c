#include <stdio.h>
#include <string.h>

int main() {
    // Exemplo da função strstr
    char str1[] = "Hello, world!";
    char str2[] = "world";
    char *result = strstr(str1, str2);
    if (result != NULL) {
        printf("A substring \"%s\" foi encontrada em \"%s\".\n", str2, str1);
        printf("A partir da posição: %ld\n", result - str1);
    } else {
        printf("A substring \"%s\" não foi encontrada em \"%s\".\n", str2, str1);
    }

    // Exemplo da função strtok
    char str3[] = "Olá, como vai você hoje?";
    char *token = strtok(str3, " ");
    printf("\nTokens encontrados:\n");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    // Exemplo da função strncpy
    char source[] = "Banana";
    char destination[8]; // Tamanho suficiente para armazenar a substring "Bana"
    strncpy(destination, source, 4);
    destination[4] = '\0'; // Adiciona o caractere nulo para finalizar a string
    printf("\nA substring copiada é: %s\n", destination);

    return 0;
}


/* strstr: A função strstr busca a primeira ocorrência de uma substring dentro de outra string. No exemplo, procuramos pela substring "world" na string "Hello, world!" e imprimimos a posição em que a substring foi encontrada.

strtok: A função strtok divide uma string em tokens (ou partes) com base em um delimitador. No exemplo, dividimos a string "Olá, como vai você hoje?" em palavras, utilizando o espaço em branco como delimitador. Em seguida, imprimimos cada token encontrado.

strncpy: A função strncpy copia uma quantidade específica de caracteres de uma string para outra. No exemplo, copiamos os primeiros 4 caracteres da string "Banana" para a string de destino destination. Em seguida, adicionamos o caractere nulo para finalizar a string. Por fim, imprimimos a substring copiada.*/