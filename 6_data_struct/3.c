#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int);

int main()
{
  struct tnode *root = NULL;
  char word[MAXWORD];
  char c;
  int linen = 1;

  while ((c = getword(word, MAXWORD)) != EOF) {
    if (c == '\n')
      linen++;
    if (isalpha(word[0]))
      root = addtree(root, word, linen);
  }
  treeprint(root);
  return 0;
}
