#include <stdio.h>
#include <string.h>

int main(void) {
  char nome[80];
  char endereco[80];
  char telefone[11];
  char *p;
  printf("Digite o nome: ");
  scanf("%[^\n]s", nome);
  printf("Digite o endereço: ");
  scanf(" %[^\n]s", endereco);
  printf("Digite o telefone: ");
  scanf(" %[^\n]s", telefone);
  p = nome;
  strcat(p, " ");
  strcat(p, endereco);
  strcat(p, " ");
  strcat(p, telefone);
  printf("Nome, endereço e telefone: %s\n", p);
  return 0;
}
