#include <stdio.h>

struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
};

struct nlist *install(char *, char *);
struct nlist *lookup(char *);

int main()
{
  char foo[] = "foo";
  char bar[] = "bar";
  char baz[] = "baz";

  install(foo, "hello");
  install(bar, "world");
  install(baz, "watt");

  install(foo, "hi");

  printf("defn: %s", (lookup("foo"))->defn);

  return 0;
}
