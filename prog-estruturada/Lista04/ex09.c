#include <stdio.h>
#include <string.h>

int main(void) {
  char usuario[9];
  char senha[9];
  char usuario2[9];
  char senha2[9];
  char *p;
  int i;
  printf("Digite o nome de usuário: ");
  scanf("%[^\n]s", usuario);
  printf("Digite a senha: ");
  scanf(" %[^\n]s", senha);
  p = usuario;
  printf("Nome de usuário: ");
  for (i = 0; i < strlen(usuario); i++) {
    if ((*(p + i) >= '0' && *(p + i) <= '9') ||
        (*(p + i) >= 'a' && *(p + i) <= 'z') ||
        (*(p + i) >= 'A' && *(p + i) <= 'Z')) {
      printf("%c", *(p + i));
    }
  }
  printf("\n");
  p = senha;
  printf("Senha: ");
  for (i = 0; i < strlen(senha); i++) {
    printf("*");
  }
  printf("\n");
  printf("Digite o nome de usuário: ");
  scanf(" %[^\n]s", usuario2);
  printf("Digite a senha: ");
  scanf(" %[^\n]s", senha2);
  if (strcmp(usuario, usuario2) == 0 && strcmp(senha, senha2) == 0) {
    printf("OK\n");
  } else {
    printf("Acesso negado.\n");
  }
  return 0;
}
