#include <stdio.h>

int main()
{
  int power;

  char ch; /* 127 8 bit */
  unsigned char u_ch; /* 255 8 bit*/
  short sh; /* 32767 16 bit */
  int in; /* 32 bit */
  unsigned int u_in; /* 32 bit */
  long ln; /* 64 bit */

  ln = 2;
  power = 1;

  while (ln > 0) {
    printf("%ld\n", ln);
    ln = ln * 2;
    ++power;
  }

  printf("power: %d\n", power);

  return 0;
}
