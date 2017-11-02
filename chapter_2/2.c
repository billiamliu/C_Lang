#include <stdio.h>

int main()
{
  int c, i;
  int lim = 100;
  char s[101];

  for (i = 0; (c = getchar()) != '\n'; ++i)
    if (c != EOF)
      if (i < lim)
        s[i] = c;
  s[i + 1] = 0;

  printf("%s\n", s);

  return 0;
}


