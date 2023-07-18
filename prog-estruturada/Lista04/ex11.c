#include <stdio.h>
#include <string.h>

int main(void) {
  char string[51];
  char *p;
  char caracteres[51];
  int i;
  int j;
  int cont;
  printf("Digite uma string de no máximo 50 caracteres: ");
  scanf("%[^\n]s", string);
  p = string;
  for (i = 0; i < strlen(string); i++) {
    cont = 0;
    for (j = 0; j < strlen(caracteres); j++) {
      if (*(p + i) == caracteres[j]) {
        cont++;
      }
    }
    if (cont == 0) {
      caracteres[strlen(caracteres)] = *(p + i);
    }
  }
  for (i = 0; i < strlen(caracteres); i++) {
    cont = 0;
    for (j = 0; j < strlen(string); j++) {
      if (caracteres[i] == *(p + j)) {
        cont++;
      }
    }
    printf("'%c' = %d\n", caracteres[i], cont);
  }
  return 0;
}