#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
  int matricula;
  float *vNotas; // Armazena as 5 notas de um aluno ao longo de um ano
  char nome[100];
} Aluno;

typedef struct Materia {

  Aluno *V;       // Armazena a informacao de n alunos !!
  float media[5]; // Armazena as 5 médias do ano
  int nAlunos;    // Número de alunos matriculados no curso.
} Materia;

Aluno *fillAluno() {
  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
  printf("Digite a matrícula do aluno: ");
  scanf("%d", &aluno->matricula);
  printf("Digite o nome do aluno: ");
  scanf(" %[^\n]", aluno->nome);

  aluno->vNotas = (float *)malloc(5 * sizeof(float));
  printf("Digite as 5 notas do aluno: ");
  for (int i = 0; i < 5; i++) {
    printf("Nota %d: ", i + 1);
    scanf("%f", &aluno->vNotas[i]);
  }

  return aluno;
}

Materia *fillMateria(int numAlunos) {
  Materia *materia = (Materia *)malloc(sizeof(Materia));
  materia->nAlunos = numAlunos;
  materia->V = (Aluno *)malloc(numAlunos * sizeof(Aluno));

  for (int i = 0; i < numAlunos; i++) {
    printf("\nPreenchendo os dados do aluno %d:\n", i + 1);
    materia->V[i] = *fillAluno();
  }

  return materia;
}

void mediaMateria(Materia *m1) {
  for (int i = 0; i < 5; i++) {
    float somaNotas = 0.0;
    for (int j = 0; j < m1->nAlunos; j++) {
      somaNotas += m1->V[j].vNotas[i];
    }
    m1->media[i] = somaNotas / m1->nAlunos;
  }
}

void mostraMateria(Materia *m1) {
  printf("\nInformações dos alunos:\n");
  for (int i = 0; i < m1->nAlunos; i++) {
    printf("\nAluno %d:\n", i + 1);
    printf("Matrícula: %d\n", m1->V[i].matricula);
    printf("Nome: %s\n", m1->V[i].nome);
    printf("Notas: ");
    for (int j = 0; j < 5; j++) {
      printf("%.2f ", m1->V[i].vNotas[j]);
    }
    printf("\n");
  }

  printf("\nMédias da matéria:\n");
  for (int i = 0; i < 5; i++) {
    printf("Prova %d: %.2f\n", i + 1, m1->media[i]);
  }
}

int main() {
  int numAlunos;

  printf("Digite o número de alunos: ");
  scanf("%d", &numAlunos);

  Materia *materia = fillMateria(numAlunos);

  mediaMateria(materia);

  mostraMateria(materia);

  return 0;
}
