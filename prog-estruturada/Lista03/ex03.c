#include <stdio.h>
#include <stdlib.h>

int* aprovados(int n, int* mat, float* notas, int* tam)
{
	int* aprovados;
	int count = 0;

/* capturando a quantidade de alunos aprovados	*/
	for (int i = 0; i < n; i++) {
		if (notas[i] >= 5)
			count++;
	}

	aprovados = malloc(sizeof(int) * count);
	if (aprovados == NULL) {
		printf("error\n");
		exit(1);
	}
	*tam = count; // atribuindo o tamanho do vetor ao ponteiro *tam

/* armazenando os alunos aprovados neste novo vetor	*/	
	int k = 0;

	for (int i = 0; i < n; i ++) {
		if (notas[i] >= 5) {
			aprovados[k] = mat[i]; 	// as matrículas e as notas são armazenadas com o mesmo índice
			k++; 		
		}
	}

	return aprovados;
}

int main(void)
{
	int n;
	int *mat;
	float *notas;
	int tam;

	printf("Há quantos alunos a serem avaliados? ");
	scanf("%d", &n);

/* alocando exatamente a memória necessária para as matrículas e as notas */
	mat = malloc(sizeof(int) * n);
	notas = malloc(sizeof(float) * n);

	if (mat == NULL || notas == NULL) {
		printf("error\n");
		return 1;
	}

/* guardando as matrículas e as notas nos seus respectivos vetores	*/
	printf("Informe a matrícula e as notas dos alunos:\n\n");
	for (int i = 0; i < n; i++) {
		printf("[%d de %d]\n", i + 1, n);
		printf("Matrícula: ");
		scanf("%d", &mat[i]);
		printf("Nota: ");
		scanf("%f", &notas[i]);
		printf("\n");
	}

	int* alunos_aprovados = aprovados(n, mat, notas, &tam);

	printf("Matrícula dos alunos aprovados: ");
	int m = 0;
	for (int k = 0; k < tam; k++) {
		printf("%d\n", alunos_aprovados[k]);
		m++;
	}

	if (m == 0) printf("Nenhum aluno foi aprovado\n");
	else if(m == 1) printf("Apenas um aluno foi aprovado\n");
	else if( m != 0) printf("%d alunos foram aprovados\n", m);

	free(mat);
	free(notas);
	free(alunos_aprovados);

	return 0;
}