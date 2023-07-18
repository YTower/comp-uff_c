#include <stdio.h>
#include <string.h>

int valida_mail(char *s) {
  int len = strlen(s);

  if (len < 2 || len > 64)
    return 0;

  if (!(s[0] >= 'a' && s[0] <= 'z'))
    return 0;

  int i;
  int letter_or_digit_count = 0;
  char previous_char = '\0';

  for (i = 0; i < len; i++) {
    char current_char = s[i];

    if (!((current_char >= 'a' && current_char <= 'z') ||
          (current_char >= '0' && current_char <= '9') || current_char == '.' ||
          current_char == '-' || current_char == '_'))
      return 0;

    if (previous_char == '.' && current_char == '.')
      return 0;

    if ((current_char >= 'a' && current_char <= 'z') ||
        (current_char >= '0' && current_char <= '9'))
      letter_or_digit_count++;

    previous_char = current_char;
  }

  if (letter_or_digit_count < 2)
    return 0;

  return 1;
}

int main() {
  char email1[] = "jsilva";
  char email2[] = "t.o.n.y-99_";
  char email3[] = "x-__7-";
  char email4[] = "3marias";
  char email5[] = "_peter";
  char email6[] = "bia.";
  char email7[] = "abc...z";

  printf("%s: %d\n", email1, valida_mail(email1));
  printf("%s: %d\n", email2, valida_mail(email2));
  printf("%s: %d\n", email3, valida_mail(email3));
  printf("%s: %d\n", email4, valida_mail(email4));
  printf("%s: %d\n", email5, valida_mail(email5));
  printf("%s: %d\n", email6, valida_mail(email6));
  printf("%s: %d\n", email7, valida_mail(email7));

  return 0;
}
