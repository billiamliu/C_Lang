#include <stdio.h>

#define MAXLINE 1000

int getl(char str[]);
void reverse(char src[], char target[]);
int length(char s[]);

int main()
{
  char str[MAXLINE];
  char rvs[MAXLINE];

  while (getl(str) != 0) {
    reverse(str, rvs);
    printf("%s\n", rvs);
  }

  return 0;
}

int getl(char s[])
{
  int i, c;

  for (i = 0; (c = getchar()) != EOF && c != '\n';  ++i)
    s[i] = c;

  if (c == '\n') {
    ++i;
  }

  s[i] = '\0';

  return i;
}

void reverse(char s[], char t[])
{
  int i, leng;

  leng = length(s);

  while (leng > 0) {
    t[i] = s[leng - 1];
    ++i;
    --leng;
  }
}

int length(char s[])
{
  int count;

  for (count = 0; s[count] != '\0'; ++count)
    ;

  return count;
}
