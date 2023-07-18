/* Faça um programa que dado um nome completo, retorne a abreviatura deste nome. Não se devem abreviar as preposições como: do, de, etc. A abreviatura deve vir separada por pontos. Ex: Paulo Jose de Almeida Prado. Abreviatura: P.J.A.P. NÃO USE GETS */

#include <stdio.h>
#include <string.h>

int main(void) {
  char nome[80];
  char *p;
  int i;
  printf("Digite o nome completo: ");
  scanf("%[^\n]s", nome);
  p = nome;
  printf("Abreviatura: ");
  printf("%c", *p);
  for (i = 0; i < strlen(nome); i++) {
    if (*(p + i) == ' ') {
      printf(".%c", *(p + i + 1));
    }
  }
  printf("\n");
  return 0;
}
