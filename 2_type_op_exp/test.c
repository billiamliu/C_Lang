#include <stdio.h>
#include <math.h>

int main()
{
  unsigned x = 6;
  printf("%d\n", x &= (x - 1));
  return 0;
}
