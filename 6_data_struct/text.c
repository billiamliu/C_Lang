#include <stdio.h>

#define NKEYS 100

char *keyword[NKEYS];
int keycount[NKEYS];

int main()
{
  void *p;
  *keyword = "cde";
  *(keyword + 1) = "foo";
  printf("%s\n", *keyword);
  p = *(keyword + 2);
  printf("%s\n", p);
}
