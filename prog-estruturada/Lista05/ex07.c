#include <stdio.h>

int *repeticao(int *vet, int tam, int *n);

int main(void) {

  int tam = 0;
  int tam_resultado = 0;
  printf("Informe o tamanho do vetor\n");
  scanf("%d", &tam);

  int *vetor = (int *) malloc(tam*sizeof(int));

  for (int i = 0; i < tam; i++) {
    printf("\nValor do index %d (Inteiros de 0 a 9):\n", i+1);
    scanf("%d", &vetor[i]);
  }

  int *resultado = repeticao(vetor, tam, &tam_resultado);
  for (int i = 0; i < tam_resultado; i++) {
    printf("%d ", resultado[i]);
  }

  free(vetor);
  return 0;
}

int *repeticao(int *vet, int tam, int *n) {

  int *resultado = (int *) malloc(tam*sizeof(int));
  int tamanho = 0;
  
  for (int i = 0; i < tam; i++) {
    for (int k = i+1; k < tam; k++) {
      if (vet[i] == vet[k]) {
        resultado[tamanho] = vet[i];
        tamanho++;
        break;
      }
    }
  }

  *n = tamanho;
  return resultado;
}
