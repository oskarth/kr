#include <stdio.h>

// C is call-by-value, so we can't change arguments a and b in the caller
// routine. Don't want to swap copies. Instead, we pass in the address of a and
// b to swap. These addresses are pointers that point to the value of a and b.
// In p = &c, the variable p is assigned the address of c, and we say that p
// points to c. In the swap routine, we use the unary operator * that
// dereferences the pointer and accesses the thing it points to, which in this
// case is the value of a and b in memory, i.e. not just a copy of a and b.

void swap(int *px, int *py) {
  int temp;
  temp = *px;
  *px = *py;
  *py = temp;
}

int main() {
  int a;
  int b;
  a = 0;
  b = 1;

  printf(" pre-swap: a=%d, b=%d\n", a, b);
  swap(&a, &b);
  printf("post-swap: a=%d, b=%d\n", a, b);
}
