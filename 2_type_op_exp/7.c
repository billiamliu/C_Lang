#include <stdio.h>
#include <math.h>

unsigned invert(unsigned number, int position, int qty);
unsigned mask(int start, int quantity);

int main()
{
  unsigned a, b, c;
  a = 54;
  b = 187;
  c = 0;
  printf("should be 42: %d\n", invert(a, 4, 3));
  printf("should be 167: %d\n", invert(b, 4, 3));
  printf("should be 126: %d\n", invert(c, 6, 6));

  return 0;
}

unsigned invert(unsigned x, int p, int n)
{
  return x ^ mask(p, n);
}

unsigned mask(int p, int n)
{
  int m;
  m = ((int) pow(2, n)) - 1;
  return m << (p + 1 - n);
}
