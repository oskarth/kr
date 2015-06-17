#include <stdio.h>

// String is just an array of characters.
// Null character '\0' represents end of string; its value is just 0.
// Internal representation: [h,e,l,l,o,\n,\0]
// Implies there's a limit to how big strings can be.
// Sure enough, `man 3 getline` tells us this is SSIZE_MAX.

// Prefix vs postfix incrementor. Increments before vs after, so it just matters
// if the value is being used, as opposed to just having an effect. In this case
// it doesn't matter, but if we said x = ++i the value of x would be different
// from x = i++, but i's value would be the same. This makes sense when you
// think about the assembly instructions it compiles into. From StackOverflow:

// LOAD    @i, r0    ;load the value of 'i' into a register from memory
// ADD     r0, 1     ;increment the value in the register
// STORE   r0, @i    ;write the updated value back to memory

// For x = ++i, it's x=i; i = i+1. For x = i++, it's i = i+1, x = i. (Silly
// mutable programming ;))

int mystrlen(char s[]) {
  int i = 0;
  
  while (s[i] != '\0') {
    ++i;
  }
  return i;
}

int main() {
  char s[] = "foobar";
  int len = mystrlen(s);
  printf("Length of %s is %d\n", s, len);
}
