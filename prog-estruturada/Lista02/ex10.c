#include <stdio.h>
#include <stdlib.h>

float media(int n, float *v)
{
	float media = 0;

	for (int i = 0; i < n; i++)
		media += v[i];

	media /= n;

	return media;
}

int main(void)
{
	int n;
	float* v;

	printf("Qual o tamanho do array? ");
	scanf("%d", &n);

	v = malloc(n * sizeof(float));

	for (int i = 0; i < n; i++)
		scanf("%f", &v[i]);

	float res = media(n, v);

	printf("%.2f\n", res);

	return 0;
}

