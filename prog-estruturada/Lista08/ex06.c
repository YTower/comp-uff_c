#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
  int mat;       /* Matricula do aluno */
  char nome[81]; /* Nome do aluno */
};
typedef struct aluno Aluno;

struct prova {
  Aluno a;              /* Aluno que fez a prova */
  float q1, q2, q3, q4; /* Nota em cada questao */
};
typedef struct prova Prova;

int compara(Prova* p1, Prova* p2) {

  float nota1 = p1->q1 + p1->q2 + p1->q3 + p1->q4;
  float nota2 = p2->q1 + p2->q2 + p2->q3 + p2->q4;

  if (nota1 > nota2)
        return 1;
    else if (nota1 < nota2)
        return 0;
  
  // se as notas forem iguais, vamos ter q comparar os nomes alfabeticamente

  int cmp = strcmp(p1->a.nome, p2->a.nome);
  if (cmp > 0) {
    return 0;
  }
  else {
    return 1;
  }
  
}

void troca(Prova **p1, Prova **p2) {
  Prova *temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

void ordena(int n, Prova **v) {
  int fim, i;
  for (fim = n - 1; fim > 0; fim--)
    for (i = 0; i < fim; i++)
      if (compara(v[i], v[i + 1]))
        troca(&v[i], &v[i + 1]);
}

int main(void) {
  printf("Hello World\n");
  return 0;
}
