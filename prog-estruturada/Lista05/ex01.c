#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *compactar(char *s) {
  int len = strlen(s);
  int start = 0;
  int end = len - 1;

  while (isspace(s[start])) {
    start++;
  }

  while (isspace(s[end])) {
    end--;
  }

  int new_len = end - start + 1;

  char *new_str = (char *)malloc((new_len + 1) * sizeof(char));
  if (new_str == NULL) {
    return NULL; 
  }

  strncpy(new_str, &s[start], new_len);
  new_str[new_len] = '\0'; 

  return new_str;
}

int main() {
  char s[] = "  nota do aluno   ";
  printf("Cadeia original: \"%s\"\n", s);

  char *compactada = compactar(s);
  if (compactada != NULL) {
    printf("Cadeia compactada: \"%s\"\n", compactada);
    free(compactada);
  } else {
    printf("Erro: não foi possível alocar memória.\n");
  }

  return 0;
}
