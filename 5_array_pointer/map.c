#include <stdio.h>

int numcmp(char *, char *);
int strcmp(const char *, const char *);
void foo(int (*comp)(void *, void *));

int main()
{
  char a;
  int b, c;

  a = b = 0;

  c = (1 ? a : b);

  return 0;
}
