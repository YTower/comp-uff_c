#include <stdio.h>
#include <string.h>

int conta_caracteres(char *s, char c) {
    int tamanho_string, contagem_caracteres;
    tamanho_string = strlen(s);
    contagem_caracteres = 0;
    
    for(int i = 0; i < tamanho_string; i++) {
        if(s[i] == c) {
            contagem_caracteres++;
        }
    }
    return contagem_caracteres;
}
