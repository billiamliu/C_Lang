#include <ctype.h>
#include <stdio.h>
#include "calc.h"

int getch(void);
void ungetch(int);

int getop(char s[])
{
  int i, c;

  /* NOTE testing static var
  static int j = 0;
  printf("GETOP has been called %d times\n", ++j);
  */

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';

  if (!isdigit(c) && c != '.' && c != '-')
    return c; /* NaN */

  i = 0;

  if (c == '-')
    while (isdigit(s[++i] = c = getch()))
      ;
  if (isdigit(c)) /* collect int part */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0';

  if (c != EOF)
    ungetch(c);

  if (!isdigit(s[i - 1]))
    return s[i - 1];

  return NUMBER;
}
