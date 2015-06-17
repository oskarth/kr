#include <stdio.h>

// This is an elegant little program.
// Use symbolic constants rather than polluting our code with magic numbers.
// EOF is just an integer in stdio.h: `grep EOF /usr/include/stdio.h`.

// gcc wc.c && ./a.out < wc.c

#define IN 1   // inside a word
#define OUT 0  // outside a word

int main() {
  int c, nl, nw, nc, state;

  state = OUT; // start outside a word
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
}
