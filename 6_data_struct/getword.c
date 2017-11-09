#include <ctype.h>
#include <stdio.h>

/* NOTE can use preprocessor to
 * optionally define getch and ungetch */
int getword(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  if ((c = getch()) == '\n')
    return c;

  while (isspace(c = getch()))
    ;

  if (c != EOF)
    *w++ = c;

  if (!isalpha(c)) {
     *w = '\0';
     return c;
   }

  for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }

  *w = '\0';

  return word[0];
}

