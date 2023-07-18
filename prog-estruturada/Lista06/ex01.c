#include <stdio.h>
#include <string.h>

int main(void) {
    // Otimo teste é uma string. A variável p recebe o endereço do último caractere da string, que é o caractere e. p = frase + strlen(frase) - 1; 
    char *frase = "Otimo teste"; 
    char *p, misterio[80]; 
    int i = 0; 
    int j = 0; 
    p = frase + strlen(frase) - 1; // Cria-se um ponteiro p e inicializa-se p com o endereço do último caractere da string frase. 
    while (*p != ' ') {            // Enquanto o caractere apontado por p for diferente de ' ', copia-se o caractere apontado por p para o vetor misterio. 
        misterio[i] = *p;          // Copia-se o caractere ' ' para o vetor misterio.
        i++;
        p--;
    }
    misterio[i] = ' ';
    i++;
    while (frase[j] != ' ') {   // Enquanto o caractere apontado por frase for diferente de ' ', copia-se o caractere apontado por frase para o vetor misterio.
        misterio[i] = frase[j]; 
        j++;
        i++;
    }
    misterio[i] = '\0';
    puts(misterio);
    return 0;
}

// Saída: etset Otimo
