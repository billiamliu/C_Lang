#include <stdio.h>

void strconcat(char *, char *);

int main()
{
  char a[100] = "hello";
  char *b = " world";
  strconcat(a, b);

  printf("concated: %s\n", a);

  return 0;
}

void strconcat(char *a, char *b)
{
  while (*++a)
    ;

  while ((*a++ = *b++))
    ;
}
