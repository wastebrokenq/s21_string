#include "../s21_string.h"
#include "../s21_sprintf.h"
#include <stdio.h>

int main() {
  char str1[1024] = "";
  char str2[1024] = "";
  const char *format = "|%s|\n";
  char *ch = NULL;
  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);

  printf("s21_sprintf: %d, result: %s\n", res1, str1);
  printf("sprintf: %d, result: %s\n", res2, str2);

  return 0;
}