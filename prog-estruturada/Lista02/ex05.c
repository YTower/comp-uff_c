//implementar uma função que recebe um vetor e retorna o maior número armazenado nesse vetor
#include <stdio.h>
#include <float.h>
#include <stdlib.h>



float max_vet (int n, float* vet)
{
	float max = FLT_MIN;

	for (int i = 0; i < n; i++) {
		if (vet[i] > max)
			max = vet[i];
	}
	return max;
}

int main(void)
{
	int n;
	float* vet;

	printf("Qual deve ser o tamanho do array? ");
	scanf("%d", &n);

	vet = malloc(n * sizeof(float));
	if (vet == NULL) return 1;

	for (int i = 0; i < n; i++) {
		printf("%d de %d\n", i + 1, n);
		scanf("%f", &vet[i]);
	}

	/* printf("Numeros coletados: ");
	
	for (int i = 0; i < n; i++) {
		printf("%.1f, ", vet[i]);
	} */

	float res = max_vet(n, vet);

	printf("O maior número armazenado é %.1f\n", res);

	free(vet);

	return 0;
}