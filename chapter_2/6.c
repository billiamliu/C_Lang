#include <stdio.h>
#include <math.h>

unsigned setbits(unsigned, int, int, unsigned);

int main()
{
  int x, y;
  unsigned result;

  x = 85;
  y = 55;

  result = setbits(x, 6, 5, y);

  printf("result should be 53: %d\n", result);

  return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  int exp, mask, nmask;

  mask = (((int) pow(2, n)) - 1) << (++p - n);
  nmask = ~mask;

  return (x & nmask) | (y & mask);
}
