#include <stdio.h>

int main()
{
  char *name[] = { "Foo", "Bar", "Hello" };
  printf("%c\n", *(*(name + 1) + 4)); /* 'H' */

  char str[14] = "Foo Bar Hello"; /* 12 char */

  str[13] = '_'; /* change i13 from '\0' */
  /* some gaps betwen i13 and i18 */
  int i = 18;
  str[i] = 'x';
  printf("%d\n", str[i + 1] - '\0'); /* 0; automatic end of line? */
  printf("%s\n", str);

  return 0;
}
