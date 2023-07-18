#include <stdio.h>

void inicializarVetorLetras(char vetor[], int tamanho) {
  int i;
  char letra = 'a';
  for (i = 0; i < tamanho; i++) {
    vetor[i] = letra;
    letra++;
  }
}

void imprimirVetor(char vetor[], int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%c ", vetor[i]);
  }
  printf("\n");
}

int main() {
  char vetor[26];

  inicializarVetorLetras(vetor, 26);
  imprimirVetor(vetor, 26);

  return 0;
}
