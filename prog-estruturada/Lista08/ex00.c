#include <stdio.h>
#include <stdlib.h>

typedef struct data {

  int dia, mes, ano;

} Data;

typedef struct local {

  char ender[81]; // endereço do local de provas
  int sala;       // numero da sala
} Local;

typedef struct notas {

  float geral;      // prova de conhecimentos gerais
  float especifica; // prova de conhecimentos especificos
} Notas;

typedef struct candidato {

  int inscr;     // numero de inscricao
  char nome[81]; // nome do candidato
  Data nasc;     // data de nascimento
  Local *loc;    // local de prova
  Notas nt;      // notas de prova

} Candidato;

void lerDadosCandidatos(Candidato *candidatos, int n) {
  for (int i = 0; i < n; i++) {
    printf("\nCandidato %d: \n", i + 1);

    printf("Número de inscrição: ");
    scanf("%d", &candidatos[i].inscr);

    printf("Nome: ");
    scanf(" %[^\n]", candidatos[i].nome);

    printf("Data de nascimento (dia mês ano): ");
    scanf("%d %d %d", &candidatos[i].nasc.dia, &candidatos[i].nasc.mes,
          &candidatos[i].nasc.ano);

    candidatos[i].loc = (Local *)malloc(sizeof(Local));
    if (candidatos[i].loc == NULL) {
      printf("Erro ao alocar memória");
      exit(1);
    }

    printf("Endereço do local de provas: ");
    scanf(" %[^\n]", candidatos[i].loc->ender);

    printf("Número da sala: ");
    scanf("%d", &candidatos[i].loc->sala);

    printf("Nota de conhecimentos gerais: ");
    scanf("%f", &candidatos[i].nt.geral);

    printf("Nota de conhecimentos específicos: ");
    scanf("%f", &candidatos[i].nt.especifica);
  }
}

void imprimirDadosCandidatos(Candidato *candidatos, int n) {

  printf("\nInformações dos candidatos:\n");

  for (int i = 0; i < n; i++) {
    printf("\nCandidato %d:\n", i + 1);
    printf("Número de inscrição: %d\n", candidatos[i].inscr);
    printf("Nome: %s\n", candidatos[i].nome);
    printf("Data de nascimento: %d/%d/%d\n", candidatos[i].nasc.dia,
           candidatos[i].nasc.mes, candidatos[i].nasc.ano);
    printf("Endereço do local de provas: %s\n", candidatos[i].loc->ender);
    printf("Número da sala: %d\n", candidatos[i].loc->sala);
    printf("Nota de conhecimentos gerais: %.2f\n", candidatos[i].nt.geral);
    printf("Nota de conhecimentos específicos: %.2f\n",
           candidatos[i].nt.especifica);
  }
}

void alterarLocalProvas(Candidato *candidatos, int n) {
  int numeroInscricao;

  printf("\nDigite o número de inscrição do candidato: ");
  scanf("%d", &numeroInscricao);

  for (int i = 0; i < n; i++) {

    if (candidatos[i].inscr == numeroInscricao) {
      printf("\nLocal de provas atual do candidato: \n");
      printf("Endereço: %s\n", candidatos[i].loc->ender);
      printf("Sala: %d\n", candidatos[i].loc->sala);

      printf("\nDigite o novo endereço do local de provas: ");
      scanf(" %[^\n]", candidatos[i].loc->ender);

      printf("\nDigite o númro novo da sala:");
      scanf("%d", &candidatos[i].loc->sala);

      printf("\nA alteração de dados foi feita com sucesso! \n");
    }
  }
}

int main(void) {
  int n;

  printf("Número de candidatos: ");
  scanf("%d", &n);

  // Alocar memória para o vetor de candidatos
  Candidato *candidatos = (Candidato *)malloc(n * sizeof(Candidato));
  if (candidatos == NULL) {
    printf("Erro ao alocar memória.");
    return 1;
  }

  int opcao;

  do {
    printf("\nMenu de opções:\n");
    printf("1 - Ler dados dos candidatos\n");
    printf("2 - Imprimir informações dos candidatos\n");
    printf("3 - Alterar endereço e sala do local de provas de um candidato\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      lerDadosCandidatos(candidatos, n);
      break;
    case 2:
      imprimirDadosCandidatos(candidatos, n);
      break;
    case 3:
      alterarLocalProvas(candidatos, n);
      break;
    case 0:
      printf("\nSaindo...\n");
      break;
    default:
      printf("\nOpção inválida. Tente novamente.\n");
      break;
    }
  } while (opcao != 0);

  for (int i = 0; i < n; i++) {
    free(candidatos[i].loc);
  }
  free(candidatos);

  return 0;
}
