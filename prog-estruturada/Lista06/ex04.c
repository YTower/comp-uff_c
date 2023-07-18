#include <ctype.h>
#include <stdio.h>

int main() {
  char line[81];
  char output[81];
  int i, j;

  printf("Digite uma linha de caracteres (até 80): ");
  fgets(line, sizeof(line), stdin);

  j = 0;
  for (i = 0; line[i] != '\0'; i++) {
    if (!isspace(line[i])) {
      output[j] = line[i];
      j++;
    }
  }
  output[j] = '\0';

  for (i = 0; output[i] != '\0'; i += 5) {
    int k;
    for (k = 0; k < 5; k++) {
      if (output[i + k] == '\0') {
        break;
      }
      output[i + k] += (k + 1);
      if (output[i + k] > 'Z') {
        output[i + k] -= 26;
      }
    }
  }

  printf("Saida: %s\n", output);
  return 0;
}
