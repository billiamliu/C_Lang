#include <stdio.h>

#define MAXLINE 1000

int getl(char[]);
void replace(char[]);

int main() {
  char str[MAXLINE];

  while (getl(str)) {
    replace(str);
    printf("%s", str);
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

  s[i] = '\0';

  return i;
}

void replace(char s[])
{
  int found, override;
  int i, skipped;
  char ret[MAXLINE];

  override = skipped = found = 0;

  for (i = 0; s[i] != '\0'; ++i)
    if (override == 1 && s[i] == '"') {
      override = 0;
      ret [i - skipped] = s[i];
    } else if (override == 1) {
      ret[i - skipped] = s[i];
    } else {
      if (s[i] == '"') {
        override = 1;
        ret[i - skipped] = s[i];
      } else {
        if (found == 1 && s[i] == '*' && s[i + 1] == '/') {
          found = 0;
          skipped = skipped + 2;
          ++i;
        } else if (found == 1) {
          ++skipped;
        } else if (s[i] == '/' && s[i + 1] == '*') {
          found = 1;
          skipped = skipped + 2;
        } else {
          ret[i - skipped] = s[i];
        }
      }
    }

  ret[i - skipped + 1] = '\0';

  for (i = 0; ret[i] != '\0'; ++i) {
    s[i] = ret[i];
  }

  s[i] = '\0';
}
