#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getl(char *line, int max);

int main(int argc, char *argv[])
{
  char line[MAXLINE];
  long lineno = 0;
  int c, except = 0, number = 0, found = 0;

  while (--argc > 0 && **++argv == '-') /* same as (*++argv)[0] */
    while ((c = *++argv[0])) /* same as *(++argv[0]) */
      switch (c) {
        case 'x':
          except = 1;
          break;
        case 'n':
          number = 1;
          break;
        default:
          printf("find: illegal option %c\n", c);
          argc = 0;
          found = -1;
          break;
      }

  if (argc != 1)
    printf("Usage: find -x -n pattern\n");
  else
    while (getl(line, MAXLINE) > 0) {
      lineno++;
      if ((strstr(line, *argv) != NULL) != except) {
        if (number)
          printf("%3ld: ", lineno);
        printf("%s", line);
        found++;
      }
    }

  return found;
}

int getl(char s[], int lim)
{
  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    if (i < (lim - 1))
      s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  if (i >= lim)
    s[lim - 1] = '\0';
  else
    s[i] = '\0';

  return i;
}
