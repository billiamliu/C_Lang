#include <stdio.h>

void squeeze(char[], char[]);

int main()
{
  char in[100] = "the quick brown fox jumps over the lazy dog";
  char remove[100] = "abcd";

  squeeze(in, remove);

  printf("%s\n", in);

  return 0;
}

void squeeze(char s[], char r[])
{
  int i, j, k, dup;
  dup = k = 0;

  for (i = 0; s[i] != '\0'; i++) {
    for (j = 0; r[j] != '\0'; j++) {
      if (s[i] == r[j])
        dup = 1;
    }
    if (dup) {
      dup = 0;
    } else {
      s[k++] = s[i];
    }
  }

  s[k] = '\0';
}
