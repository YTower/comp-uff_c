#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 81
#define NUM_ALUNOS 5

typedef struct _ALUNO {
  char nome[MAX_NOME];
  float nota1, nota2;
} ALUNO;

void exibirAlunosAprovados(FILE *arquivo) {
  ALUNO aluno;

  rewind(arquivo); 

  while (fread(&aluno, sizeof(ALUNO), 1, arquivo) == 1) {
    float media = (aluno.nota1 + aluno.nota2) / 2.0;
    if (media > 6.0) {
      printf("Aluno: %s\n", aluno.nome);
      printf("Média: %.2f\n", media);
      printf("----------------------------\n");
    }
  }
}

int exibirMenu() {
  int opcao;

  printf("----- Menu -----\n");
  printf("1. Incluir aluno\n");
  printf("2. Alterar aluno\n");
  printf("3. Consultar aluno\n");
  printf("4. Excluir aluno\n");
  printf("5. Exibir alunos aprovados\n");
  printf("6. Sair\n");
  printf("Escolha uma opção: ");
  scanf("%d", &opcao);

  return opcao;
}

void incluirAluno(FILE *arquivo) {
  ALUNO aluno;

  printf("Digite o nome do aluno: ");
  scanf(" %[^\n]s", aluno.nome);
  printf("Digite a nota 1 do aluno: ");
  scanf("%f", &aluno.nota1);
  printf("Digite a nota 2 do aluno: ");
  scanf("%f", &aluno.nota2);

  fseek(arquivo, 0, SEEK_END); 
  fwrite(&aluno, sizeof(ALUNO), 1, arquivo);

  printf("Aluno incluído com sucesso.\n");
}

void alterarAluno(FILE *arquivo) {
  ALUNO aluno;
  char nomeBusca[MAX_NOME];
  int encontrado = 0;

  printf("Digite o nome do aluno que deseja alterar: ");
  scanf(" %[^\n]s", nomeBusca);

  rewind(arquivo); 

  while (fread(&aluno, sizeof(ALUNO), 1, arquivo) == 1) {
    if (strcmp(aluno.nome, nomeBusca) == 0) {
      printf("Digite o novo nome do aluno: ");
      scanf(" %[^\n]s", aluno.nome);
      printf("Digite a nova nota 1 do aluno: ");
      scanf("%f", &aluno.nota1);
      printf("Digite a nova nota 2 do aluno: ");
      scanf("%f", &aluno.nota2);

      fseek(arquivo, -sizeof(ALUNO), SEEK_CUR); 
      fwrite(&aluno, sizeof(ALUNO), 1, arquivo);

      printf("Aluno alterado com sucesso.\n");
      encontrado = 1;
      break;
    }
  }

  if (!encontrado) {
    printf("Aluno não encontrado.\n");
  }
}

void consultarAluno(FILE *arquivo) {
  ALUNO aluno;
  char nomeBusca[MAX_NOME];
  int encontrado = 0;

  printf("Digite o nome do aluno que deseja consultar: ");
  scanf(" %[^\n]s", nomeBusca);

  rewind(arquivo); 

  while (fread(&aluno, sizeof(ALUNO), 1, arquivo) == 1) {
    if (strcmp(aluno.nome, nomeBusca) == 0) {
      printf("Aluno: %s\n", aluno.nome);
      printf("Nota 1: %.2f\n", aluno.nota1);
      printf("Nota 2: %.2f\n", aluno.nota2);
      printf("----------------------------\n");
      encontrado = 1;
      break;
    }
  }

  if (!encontrado) {
    printf("Aluno não encontrado.\n");
  }
}

void excluirAluno(FILE *arquivo) {
  ALUNO aluno;
  char nomeBusca[MAX_NOME];
  int encontrado = 0;

  printf("Digite o nome do aluno que deseja excluir: ");
  scanf(" %[^\n]s", nomeBusca);

  FILE *temp = fopen("temp.bin", "wb");

  rewind(arquivo);

  while (fread(&aluno, sizeof(ALUNO), 1, arquivo) == 1) {
    if (strcmp(aluno.nome, nomeBusca) != 0) {
      fwrite(&aluno, sizeof(ALUNO), 1, temp);
    } else {
      encontrado = 1;
    }
  }

  fclose(arquivo);
  fclose(temp);

  remove("alunos.bin"); 
  rename("temp.bin",
         "alunos.bin"); 

  if (encontrado) {
    printf("Aluno excluído com sucesso.\n");
  } else {
    printf("Aluno não encontrado.\n");
  }
}

int main() {
  FILE *arquivo;
  int opcao;

  arquivo = fopen("alunos.bin", "rb+");
  if (arquivo == NULL) {
    arquivo = fopen("alunos.bin", "wb+");
    if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo.\n");
      return 1;
    }
  }

  do {
    opcao = exibirMenu();

    switch (opcao) {
    case 1:
      incluirAluno(arquivo);
      break;
    case 2:
      alterarAluno(arquivo);
      break;
    case 3:
      consultarAluno(arquivo);
      break;
    case 4:
      excluirAluno(arquivo);
      break;
    case 5:
      exibirAlunosAprovados(arquivo);
      break;
    case 6:
      printf("Encerrando o programa...\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
      break;
    }

    printf("\n");
  } while (opcao != 6);

  fclose(arquivo);

  return 0;
}
