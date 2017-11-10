enum { KEYWORD = 01, EXTERNAL = 02, STATIC = 04 };

struct {
  unsigned int is_keyword : 1; /* field width in bits */
  unsigned int is_extern : 1;
  unsigned int is_static : 1;
} flags;

/* operations on bit struct
 * flags.is_extern = flags.is_static = 1;
 * if (flags.is_extern == 0)
 */
