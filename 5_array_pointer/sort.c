#include <stdio.h>
#include <string.h>

#define MAXLINES 1000
#define MAXLEN 1000
#define ALLOCSIZE 10000

char *lineptr[MAXLINES];
float atof(char *);
int getl(char s[], int lim);

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

int numcmp(char *, char *);
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

char *alloc(int);

int main(int argc, char *argv[])
{
  int nlines;
  int numeric = 0; /* 1 if numeric sort */

  if (argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort((void **) lineptr, 0, nlines - 1,
        (numeric ?
         (int (*)(void *, void *))numcmp :
         (int (*)(void *, void *))strcmp));
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }
}

void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
  int i, last;
  void swap(void *v[], int, int);

  if (left >= right)
    return;

  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if ((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last - 1, comp);
  qsort(v, last + 1, right, comp);
}

int numcmp(char *s1, char *s2)
{
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);

  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else return 0;
}

void swap(void *v[], int i, int j)
{
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}


int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;

  while ((len = getl(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len - 1] = '\0'; /* delete newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
    }

  return nlines;
}

void writelines(char *lineptr[], int nlines)
{
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
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

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf; /* same as *allocp = &allocbuf[0] */

char *alloc(int n) /* return pointer to n chars */
{
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else
    return 0;
}

void afree(char *p)
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}
