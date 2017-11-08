#include <stdio.h>

#define MAXLINE 1000
#define TABSPACES 2

int getl(char s[]);
void detab(char s[]);
void display(char s[]);

int main()
{
  char str[MAXLINE];

  while (getl(str) > 0) {
    detab(str);
    display(str);
  }

  return 0;
}

int getl(char s[])
{
  int i, c;

  for (i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n')
    ++i;

  s[i] = '\0';

  return i;
}

void detab(char s[])
{
  int i, j, idx;
  char ret[MAXLINE * TABSPACES];

  idx = 0;

  for (i = 0; s[i] != '\0'; ++i) {
    if (s[i] == '\t') {
      for (j = 0; j < TABSPACES; ++j) {
        ret[idx] = ' ';
        ++idx;
      }
    } else {
      ret[idx] = s[i];
      ++idx;
    }
  }

  for (j = 0; j < idx; ++j)
    s[j] = ret[j];

  s[j + 1] = '\0';
}

void display(char s[])
{
  printf("%s\n", s);
}
