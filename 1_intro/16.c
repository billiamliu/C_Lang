#include <stdio.h>

#define MAXDISP 20

int getl(char line[], int maxline); /* getline */
void copy(char to[], char from[]);

int main()
{
  int len; /* current line length */
  int max; /* max so far */
  char line[MAXDISP]; /* current input line */
  char longest[MAXDISP]; /* longest line so far */

  max = 0;

  while ((len = getl(line, MAXDISP)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }

  if (max > MAXDISP) /* there was a line */
    printf("longest: %d, line: %s...\n", max, longest);
  else if (max > 0)
    printf("longest: %d, line: %s\n", max, longest);

  return 0;
}

int getl(char s[], int lim)
{
  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    if (i < (lim - 1))
      s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  if (i >= lim)
    s[lim - 1] = '\0';
  else
    s[i] = '\0';

  return i;
}

void copy(char to[], char from[])
{
  int i;
  i = 0;

  while ((to[i] = from[i]) != '\0')
    ++i;
}
