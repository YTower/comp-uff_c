#define MAX 4
#define MAXNOME 31
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void atribui(char **nomes, int indice, char *nome) {
  
  strcpy(nomes[indice], nome);
  
}
char *get_sobrenome(char *nome) {

  char *sobrenome = strrchr(nome, ' ');
    if (sobrenome != NULL) {
      // Avançar um caractere pra passar do espaço em branco e chegar no sobrnome
      sobrenome++;
    }

  return sobrenome;
  
}


int main() {
  int i;
  char **nomes;
  char *sobrenome;
  nomes = (char **)malloc(MAX * sizeof(char *));
  for (i = 0; i < MAX; i++) {
    nomes[i] = (char *)malloc(sizeof(char) * MAXNOME);
  }
  atribui(nomes, 0, "Fulano Silva");
  atribui(nomes, 1, "Maria do Carmo");
  atribui(nomes, 2, "Beltrano Belmonte"); 
  atribui(nomes, 3, "Pedro dos Santos");
for (i=0 ; i<MAX ; i++) {
    sobrenome = get_sobrenome(nomes[i]);
    printf("\n%s ", sobrenome);
    printf(" %d", strlen(sobrenome) > 5 ? i : 0); // 2o printf
}

printf("\n%c", nomes[0][3]); // 3o printf

}

// Segundo print vai imprimir cada sobrenome da matriz seguido por um espaço e 5 se o sobrenome tiver mais que 5 letras ou seguido por 0 se o sobrenome tiver menos que 5 letras ou 5 letras.

// Terceiro print irá imprimir a letra "a", pois está se referindo à posição do 4 da string "Fulano Silva".
