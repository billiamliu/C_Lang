#include <stdio.h>

struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
};

struct nlist *install(char *, char *);
struct nlist *lookup(char *);
int undef(char *);

int main()
{
  char foo[] = "foo";
  char bar[] = "bar";
  char baz[] = "baz";

  install(foo, "hello");
  install(bar, "world");
  install(baz, "watt");

  install(foo, "hi");

  printf("defn: %s\n", lookup("foo")->defn);
  printf(undef("foo") == 0 ? "removed\n" : "already removed\n");
  printf(undef("foo") == 0 ? "removed\n" : "already removed\n");

  return 0;
}
