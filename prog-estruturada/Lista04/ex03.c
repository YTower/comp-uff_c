#include <stdio.h>

int main() {
  char palavra[50];
  char primeiraLetra, ultimaLetra;
  int numeroLetras = 0;

  printf("Digite uma palavra: ");
  scanf("%s", palavra);

  primeiraLetra = palavra[0];

  while (palavra[numeroLetras] != '\0') {
    numeroLetras++;
  }

  ultimaLetra = palavra[numeroLetras - 1];

  printf("Primeira letra: %c\n", primeiraLetra);
  printf("Última letra: %c\n", ultimaLetra);
  printf("Número de letras: %d\n", numeroLetras);

  return 0;
}
