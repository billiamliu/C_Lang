#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* STRUCTS */

struct linelist {
  struct linelist *next;
  int line;
};

struct tnode {
  char *word;
  int count;
  struct linelist *linelist;
  struct tnode *left;
  struct tnode *right;
};

/* HEADERS */

char *strdupe(char *);
struct tnode *talloc(void);
struct linelist *lalloc(void);
struct linelist *addline(struct linelist *, int n);
void lineprint(struct linelist *);

/* CODE */

struct tnode *
addtree(struct tnode *p, char *w, int n)
{
  int cond;

  if (p == NULL) {
    p = talloc();
    p->word = strdupe(w);
    p->count = 1;
    p->linelist = NULL;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++;
  else if (cond < 0)
    p->left = addtree(p->left, w, n);
  else
    p->right = addtree(p->right, w, n);

  p->linelist = addline(p->linelist, n);

  return p;
}

struct linelist *
addline(struct linelist *ll, int n)
{
  if (ll == NULL) {
    ll = lalloc();
    ll->line = n;
    ll->next = NULL;
  } else if (ll->line == n) {
    return ll;
  } else {
    ll->next = addline(ll->next, n);
  }
  return ll;
}

void treeprint(struct tnode *p)
{
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s // lines: ", p->count, p->word);
    lineprint(p->linelist);
    printf("\n");
    treeprint(p->right);
  }
}

void lineprint(struct linelist *ll)
{
  if (ll != NULL) {
    printf("%d ", ll->line);
    lineprint(ll->next);
  }
}

char *strdupe(char *s)
{
  char *p;
  p = (char *) malloc(strlen(s) + 1);
  if (p != NULL)
    strcpy(p, s);
  return p;
}

struct tnode *talloc(void)
{
  return (struct tnode *) malloc(sizeof(struct tnode));
}

struct linelist *lalloc(void)
{
  return (struct linelist *) malloc(sizeof(struct linelist));
}
