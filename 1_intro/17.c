#include <stdio.h>

#define THRESHOLD 20
#define MAXLINE 1000

int getl(char string[]);

int main()
{
  int len;
  char line[MAXLINE];

  while ((len = getl(line)) > 0)
    if (len > THRESHOLD)
      printf("%s", line);

  return 0;
}

int getl(char s[])
{
  int i, c;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  
  return i;
}
