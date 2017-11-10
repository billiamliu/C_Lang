#include <string.h>
#include <stdlib.h>

struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];
struct nlist *install(char *, char *);

unsigned hash(char *s)
{
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;

  return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
  struct nlist *np;

  /* standard convention for LL
   * for (p = head; p != NULL; p = p->next) */
  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0)
      return np;

  return NULL;
}

/* ex. 6-5 */
int undef(char *name)
{
  struct nlist *np1, *np2;

  if ((np1 = lookup(name)) == NULL)
    return -1;

  for (
      np1 = np2 = hashtab[hash(name)];
      np1 != NULL;
      np2 = np1, np1 = np1->next) {
    if (strcmp(name, np1->name) == 0) {
      if (np1 == np2) /* first element was target */
        hashtab[hash(name)] = np1->next;
      else
        np2->next = np1->next;

      free(np1->name);
      free(np1->defn);
      free(np1);

      return 0;
    }
  }

  return 0;
}

struct nlist *install(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL) {
    np = (struct nlist *) malloc(sizeof(*np));
    if (np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else
    free((void *) np->defn); /* free previous defn */

  if ((np->defn = strdup(defn)) == NULL)
    return NULL;

  return np;
}
