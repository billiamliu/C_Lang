#include <stdio.h>

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("error: UNGETCH -- too many char in buffer\n");
  else
    buf[bufp++] = c;
}

