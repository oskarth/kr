#include <stdio.h>
#include <stdlib.h>

// Wrongs
// 1. c[0] = 200 does change value of a, because it is a[0].
// 2. 3[c] = 302, what?
// 3. Changing c doesn't change a, need to check *c for that.
// 4. Casting c+1 into char* then int* doesn't give same, since sizeof char is 1
// and size of int is 1. So we get an offset and thus gibberish.

// x[i] is syntactic sugar for *(x+i), where x is a pointer.
// Oh! so this would just mean: *(3+c). Presumably that's the same as c+3.

void
f(void)
{
  int a[4]; // 4*4 bytes memory, each 4 byte one int (2^(32) - 1)
  int *b = malloc(16); // sizeof(int) = 4, so same type as a
  int *c; // int-pointer
  int i; // int

  // Three distinct memory addresses.
  printf("1: a = %p, b = %p, c = %p\n", a, b, c);

  c = a; // c* now points to a or a[0]
  for (i = 0; i < 4; i++)
    a[i] = 100 + i;
  c[0] = 200; // this is really a[0]

  // 200, 101, 102, 103
  printf("2: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
         a[0], a[1], a[2], a[3]);

  c[1] = 300;
  *(c + 2) = 301; // same as c[2], so a[2]
  3[c] = 302; // just syntactic sugar for *(3+c)

  // 200, 300, 301, 302
  printf("3: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
         a[0], a[1], a[2], a[3]);

  c = c + 1; // only affects c, and *c now points at a[1]
  *c = 400; // now *c points to 400, and c is a[1] elem so

  // 200, 400, 301, 302
  printf("4: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
         a[0], a[1], a[2], a[3]);

  c = (int *) ((char *) c + 1); // casts c+1 into char* then into int*
  // because sizeof different we get gibberish. For how long?
  *c = 500; // a[1]+1 byte then int,
  
  // actually I don't grok why a[3] is still 302.
  // 200, 400, 500, 302
  printf("5: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
         a[0], a[1], a[2], a[3]);

  b = (int *) a + 1;
  c = (int *) ((char *) a + 1);

  // Three different memory addresses, no?
  printf("6: a = %p, b = %p, c = %p\n", a, b, c);
}

int
main(int ac, char **av)
{
  f();
  return 0;
}

