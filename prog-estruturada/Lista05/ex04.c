#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *cifra_cesar(char *msg) {
    int len = strlen(msg);
    char *codificado = (char *) malloc((len + 1) * sizeof(char)); 

    if (codificado == NULL) {
        return NULL; 
    }

    int i;
    for (i = 0; i < len; i++) {
        char caractere = msg[i];

        if (isalpha(caractere)) {
            char base;

            if (islower(caractere)) {
                base = 'a';
            } else {
                base = 'A'; 
            }

            codificado[i] = (caractere - base + 3) % 26 + base;
        } else {
            codificado[i] = caractere;
        }
    }

    codificado[len] = '\0';

    return codificado;
}

int main() {
    char msg[] = "zebra";
    printf("Mensagem original: %s\n", msg);

    char *codificado = cifra_cesar(msg);
    if (codificado != NULL) {
        printf("Mensagem codificada: %s\n", codificado);
        free(codificado); 
    } else {
        printf("Erro: não foi possível alocar memória.\n");
    }

    return 0;
}
