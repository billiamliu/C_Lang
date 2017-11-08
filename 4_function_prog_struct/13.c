#include <stdio.h>

#define MAXLINE 100
#define EOL '\0'

int getl(char s[]);
int strleng(char s[], int i);
void reverse(char src[], char dest[]);
void reverseiter(char s[], char d[], int si, int di);

int main()
{
  char str[MAXLINE];
  char dest[MAXLINE];


  while (getl(str)) {
    reverse(str, dest);
    printf("%s", dest);
  }

  return 0;
}

int getl(char s[])
{
  int i, c;

  for (i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = EOL;

  return i;
}

/* naiive implementation, can be more efficient to keep an index on src[] */
void reverse(char src[], char dest[])
{
  int leng = strleng(src, 0) - 1/* EOL */; 
  reverseiter(src, dest, leng, 0);
}

int strleng(char s[], int i)
{
  return s[i] == EOL ? 0 : (1 + strleng(s, ++i));
}

void reverseiter(char src[], char dest[], int si, int di)
{
  if (si < 0) {
    dest[di + 1] = EOL;
    return;
  }

  dest[di] = src[si];

  reverseiter(src, dest, --si, ++di);
}
