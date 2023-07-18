#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *estado[27] =
{"AC","AL","AM","AP","BA","CE","DF","ES","GO","MA","MG","MS","MT","PA",
"PB","PE","PI","PR","RJ","RN","RO","RR","RS","SC","SE","SP","TO"};

typedef struct assalariados {
  char nome[51];
  char sexo;
  int idade;
  float salario;
  char estado[3];
} Assalariados;

Assalariados *cadastra(char *nome, char sexo, int idade, float salario, char *estado) {

  Assalariados *assalariado = (Assalariados *) malloc(sizeof(Assalariados));

  //Copia os valores dos parâmetros para os campos da estrutura

  strncpy(assalariado->nome, nome, 50);
  assalariado->nome[50] = '\0'; //Garante que a string seja terminada corretamente
  assalariado->sexo = sexo;
  assalariado->idade = idade;
  assalariado->salario = salario;
  strncpy(assalariado->estado, estado, 2);
  assalariado->estado[2] = '\0'; //Garante que a string seja terminada corretamente

  return assalariado;
  
}

void relatorio(Assalariados **ptr, int numAssalariados) {

  int i, j, contagem;
    for (i = 0; i < 27; i++) {
        contagem = 0;
        for (j = 0; j < numAssalariados; j++) {
            if (ptr[j]->sexo == 'M' && ptr[j]->idade > 40 && ptr[j]->salario > 1000 && strcmp(ptr[j]->estado, estado[i]) == 0) {
                contagem++;
            }
        }
        if (contagem > 0) {
            printf("Estado=%s com %d homens maiores de 40 anos e salário maior que R$ 1000,00\n", estado[i], contagem);
        }
    }
}

void imprime(Assalariados **ptr, int numAssalariados) {
  int i;
  for(i = 0; i < numAssalariados; i++) {

    printf("Nome: %s\n", ptr[i]->nome);
    printf("Sexo: %c\n", ptr[i]->sexo);
    printf("Idade: %d\n", ptr[i]->idade);
    printf("Salário: %.2f\n", ptr[i]->salario);
    printf("Estado: %s\n\n", ptr[i]->estado);
  }
}



int main(void) {
    Assalariados **pessoas;
    int numAssalariados = 3;

    pessoas = (Assalariados **) malloc(numAssalariados * sizeof(Assalariados *));
    pessoas[0] = cadastra("Fulano de tal", 'M', 45, 1500.00, "RJ");
    pessoas[1] = cadastra("Ciclano", 'M', 50, 2500.00, "RS");
    pessoas[2] = cadastra("Beltrano", 'M', 42, 500.00, "RS");

    imprime(pessoas, numAssalariados);
    relatorio(pessoas, numAssalariados);

    // Libera a memória alocada
    for (int i = 0; i < numAssalariados; i++) {
        free(pessoas[i]);
    }
    free(pessoas);


    return 0;
}
