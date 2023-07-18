#include <stdio.h>

int main(void) {

  int tam = 0;
  printf("Informe o tamanho do vetor\n");
  scanf("%d", &tam);

  int *vetor = (int *) malloc(tam*sizeof(int));

  for (int i = 0; i < tam; i++) {
    printf("\nValor do index %d (Inteiros de 0 a 9):\n", i+1);
    scanf("%d", &vetor[i]);
  }

  for (int i = 0; i < tam; i++) {
    for (int k = i+1; k < tam; k++) {
      if (vetor[i] == vetor[k]) {
        printf("%d ", vetor[i]);
        break;
      }
    }
  }

  free(vetor);
  return 0;
}
