#include <stdio.h>

void repeticao(int *vet, int tam);

int main(void) {

  int tam = 0;
  printf("Informe o tamanho do vetor\n");
  scanf("%d", &tam);

  int *vetor = (int *) malloc(tam*sizeof(int));

  for (int i = 0; i < tam; i++) {
    printf("\nValor do index %d (Inteiros de 0 a 9):\n", i+1);
    scanf("%d", &vetor[i]);
  }

  repeticao(vetor, tam);

  free(vetor);
  return 0;
}

void repeticao(int *vet, int tam) {
  for (int i = 0; i < tam; i++) {
    for (int k = i+1; k < tam; k++) {
      if (vet[i] == vet[k]) {
        printf("%d ", vet[i]);
        break;
      }
    }
  }
}
