#include <stdio.h>
#include <stdlib.h>

int *premiados(int n, int *inscr, float *t1, int p1,float *t2, int p2, int *tam)
{
	int count = 0;
	float maior = 0;
	float* media = malloc(sizeof(float) * n);
	if (media == NULL) {
		printf("error 02\n");
		exit(1);
	}

	/*	guardando as médias de cada participante no vetor media e verificando quais foram as maiores médias	*/

	for (int i = 0; i < n; i++) {
		media[i] = ((t1[i] * p1) + (t2[i] * p2))/(p1 + p2);
		if (media[i] > maior) {
			maior = media[i];
			count = 1;
		} else if (media[i] == maior)
			count++;
	}

	int* premiados = malloc(sizeof(int) * count);
	if (premiados == NULL) { 
		printf("error 03\n");
		free(media);
		exit(1);
	}
	int index = 0;
	for (int i = 0; i < n; i++) {
    	if (media[i] == maior)
       		premiados[index] = inscr[i];
	}

	*tam = count;
	free(media);

	return premiados;
}

int main(void)
{
	int n;
	int p1;
	int p2;
	int tam;
	
	printf("Quantas pessoas participaram do concurso? ");
	scanf("%d", &n);
	printf("\n");

	/* ALocando dinamicamente os ponteiros inscr, t1 e t2*/
	int* inscr = malloc(sizeof(int) * n);
	float* t1 = malloc(sizeof(float) * n);
	float* t2 = malloc(sizeof(float) * n);

	if (inscr == NULL || t1 == NULL || t2 == NULL) {
		printf("error 01\n");
		exit(1);
	}

	printf("Preencha com as informações de cada participante:\n\n");

	/* guardando as informações dos participantes nos seu respectivos ponteiros	*/
	for (int i = 0; i < n; i++) {
		printf("[%d de %d]\n", i + 1, n);
		printf("Inscrição: ");
		scanf("%d", &inscr[i]);
		printf("Nota 1: ");						// as notas e as inscrições de cada participante são armazenadas no mesmo índice
		scanf("%f", &t1[i]);
		printf("Nota 2: ");
		scanf("%f", &t2[i]);
		printf("\n");
	}

	printf("Informe os pesos da primeira e da segunda nota: ");
	scanf("%d %d", &p1, &p2);

	int* res = premiados(n, inscr, t1, p1, t2, p2, &tam);
	if (res == NULL) {
		printf("error 04\n");
		return 1;
	}
	printf("\nOs participantes premiados foram:\n");
	for (int i = 0; i < tam; i++) {
		printf("%d ", res[i]);
	}
	
	printf("\nParabéns!\n");

	return 0;
}