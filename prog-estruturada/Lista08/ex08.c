#include <stdio.h>

struct ALUNO {
  char nome[20];
  double media;
};

void ordena(ALUNO turma[], int tam) {
  int i, foraOrdem, jaOrdenados = 0;
  ALUNO temp;

  do {
    foraOrdem = 0;

    for (i = 0; i < tam - 1 - jaOrdenados; i++) {
      if (turma[i].media > turma[i + 1].media) {
        temp = turma[i];
        turma[i] = turma[i + 1];
        turma[i + 1] = temp;
        foraOrdem = 1;
      }
    }

    jaOrdenados++;
  } while (foraOrdem);
}

int main() {
  const int tam = 4;
  ALUNO turma[tam] = {
      {"João", 8.5}, {"Vinícius", 9.0}, {"Thales", 7.0}, {"Yuri", 6.5}};

  printf("Turma antes da ordenação:\n");
  for (int i = 0; i < tam; i++) {
    printf("Nome: %s, Média: %.1lf\n", turma[i].nome, turma[i].media);
  }

  ordena(turma, tam);

  printf("\nTurma após a ordenação:\n");
  for (int i = 0; i < tam; i++) {
    printf("Nome: %s, Média: %.1lf\n", turma[i].nome, turma[i].media);
  }

  return 0;
}
