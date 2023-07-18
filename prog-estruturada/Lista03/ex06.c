#include <ctype.h>
#include <stdio.h>
#include <string.h>

void CamelCase(char *s) {
  int len = strlen(s);
  int i;

  s[0] = tolower(s[0]);

  for (i = 1; i < len; i++) {
    if (s[i] == ' ') {
      s[i + 1] = toupper(s[i + 1]);
      memmove(&s[i], &s[i + 1], len - i);
      len--;
    }
  }
}

int main() {
  char s[20];
  strcpy(s, "Media da turma");
  printf("Cadeia original: %s\n", s);
  CamelCase(s);
  printf("Cadeia em Camel Case: %s\n", s);

  return 0;
}
