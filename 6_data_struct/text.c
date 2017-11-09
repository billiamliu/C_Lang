#include <stdio.h>

int main()
{
  int *p[10];
  int foo[] = { 1, 2, 3, 4 };
  int bar[] = { 1, 2, 3 };
  int baz[] = { 1, 2 };

  p[0] = foo;
  p[1] = bar;
  p[2] = baz;

  printf("int: %d\n", p[2][0]);

  int a[10];
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;

  printf("int: %d\n", a[2]);
  printf("int: %d\n", a[3]);
}
