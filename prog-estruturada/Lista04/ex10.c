#include <stdio.h>
#include <string.h>

int main(void) {
  char string[21];
  char *p;
  int i;
  printf("Digite uma string de no máximo 20 caracteres: ");
  scanf("%[^\n]s", string);
  p = string;
  for (i = strlen(string) - 1; i >= 0; i--) {
    printf("%c", *(p + i));
  }
  printf("\n");
  return 0;
}
