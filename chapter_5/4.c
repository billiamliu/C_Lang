#include<stdio.h>

int strend(char *, char *);

int main()
{
  char a[] = "hello world";
  char b[] = "orld";
  char c[] = "wat";

  if (strend(a, b))
    printf("strings has same ending\n");
  else
    printf("strings does not have same ending\n");

  if (strend(a, c))
    printf("strings has same ending\n");
  else
    printf("strings does not have same ending\n");

  return 0;
}

int strend(char *a, char *b)
{
  int i = 0;

  while (*a++)
    ;

  do
    i++; /* to account for '\0' */
  while (*b++);

  while (*--a == *--b)
    i--;

  return i == 0;
}
