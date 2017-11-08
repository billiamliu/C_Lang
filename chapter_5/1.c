#include <ctype.h>
#include <stdio.h>

#define MAXLINE 10

/* from ch.c */
int getch(void);
void ungetch(int);

int getint(int *);

int main()
{
  int i, n, list[MAXLINE], isint;

  for (n = 0; n < MAXLINE && (isint = getint(&list[n])) != EOF && isint != 0; n++)
    printf("%d\n", list[n]);

  printf("\nValid Int List:\n");
  i = 0;
  do
    printf("%d\n", list[i]);
  while (++i < n);

  return 0;
}

int getint(int *pn)
{
  int c, sign;

  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-')
    c = getch();

  if (!isdigit(c)) {
    ungetch(c);
    ungetch((sign == 1) ? '+' : '-');
    return 0;
  }

  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10 * *pn + (c - '0');
  }

  *pn *= sign;

  if (c != EOF)
    ungetch(c);

  return c;
}
