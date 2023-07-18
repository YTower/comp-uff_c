#include <stdio.h>
#include <string.h>

void conta_vogais(char *s, int *n) {
    int tamanho_string, contagem_vogais;
    tamanho_string = strlen(s);
    contagem_vogais = 0;
    
    for(int i = 0; i < tamanho_string; i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] ==  'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            contagem_vogais++;
        }
    }
    *n = contagem_vogais;
}


int main() {
    int n = 0;
    char s[100];
    scanf("%s", s);
    conta_vogais(s, &n);
    printf("%d\n", n);
    return 0;
}
