#include <stdio.h>
#include <string.h>

int main(void) {
  char palavra1[80];
  char palavra2[80];
  char *p1;
  char *p2;
  int i;
  int j;
  printf("Digite a primeira palavra: ");
  scanf("%[^\n]s", palavra1);
  printf("Digite a segunda palavra: ");
  scanf(" %[^\n]s", palavra2);
  p1 = palavra1;
  p2 = palavra2;
  if (strcmp(p1, p2) == 0) {
    printf("As palavras são iguais.\n");
  } else {
    printf("As palavras são diferentes.\n");
  }
  for (i = 0; i < strlen(palavra1); i++) {
    if (*(p1 + i) == *p2) {
      for (j = 0; j < strlen(palavra2); j++) {
        if (*(p1 + i + j) == *(p2 + j)) {
          if (j == strlen(palavra2) - 1) {
            printf("A segunda palavra é uma substring da primeira.\n");
            return 0;
          }
        } else {
          break;
        }
      }
    }
  }
  printf("A segunda palavra não é uma substring da primeira.\n");
  return 0;
}
