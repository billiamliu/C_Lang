#include <stdio.h>

int main()
{
  int i = 0;
  int *p;
  p = &i;
  *p = 1;

  return 0;
}
