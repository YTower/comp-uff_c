//implemente uma função que recebe um vetor e retorna quantos numeros maiores do que x existem nesse vetor
#include <stdio.h>
#include <stdlib.h>


int maiores(int n, int* vet, int x) 
{	
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (vet[i] > x)
			count++;
	}
	return count;
}

int main(void)
{	
	int n;
	int x;
	int* vet;

	printf("Qual será o tamanho do array? ");
	scanf("%d", &n);

	vet = malloc(n * sizeof(int));
	if (vet == NULL) return 1;

	for (int i = 0; i < n; i++) {
		printf("%d de %d: ", i + 1, n);
		scanf("%d", &vet[i]);
	}
	printf("Informe o valor de x: ");
	scanf("%d", &x);

	int res = maiores(n, vet, x);
	printf("A quantidade de números maiores do que x neste array é %d\n", res);

	free(vet);

	return 0;
}