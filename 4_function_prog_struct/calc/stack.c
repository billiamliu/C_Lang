#include <stdio.h>

#define MAXDEPTH 100

static int sp = 0;
static double val[MAXDEPTH];

void push(double f)
{
  if (sp < MAXDEPTH)
    val[sp++] = f;
  else
    printf("error: PUSH -- stack full, can't push %g\n", f);
}

double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: POP -- stack empty\n");
    return 0.0;
  }
}

