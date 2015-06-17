#include <stdio.h>

// Initialize array with {a,b,c} apparently. I'm not sure why, but why not I
// guess. Each element has a fixed size and is in some offset from the start of
// the array in memory. For example, char foo[] = "oui"; is just shorthand for
// char[] foo[] = { 'o', 'u', 'i, '\0'}. So use {a,b,c} to represent memory
// rather than [a,b,c] like you did in strlen.

// To print arrays, we have to loop over. Either we know size, O(1), or
// nil-terminated O(n). Otherwise we seem to be screwed. How does sizeof work in
// that case? Are initialized arrays always nil-terminated?

// As an aside, if a string isn't nil-terminated it's ill-formed, but the
// behavior its undefined. Here's a joke about that:
// Two strings walk into a bar. The bartender says, "What'll it be?". The first
// string says, "I'll have a gin and tonic#MV*()>SDk+!^
// &@P&]JEA&#65535;Segmentation Fault". The second string says, "You'll have to
// excuse my friend, he's not null-terminated."

// Apparently array initialization without a dimension is deduced from the
// elements, but only the outermost one, otherwise we get a compiler error:
// error: array has incomplete element type 'int []'
// This seems to imply we can't do a one-pass, but that's probably the case
// anyway, and I don't know enough about compilers to continue down this rabbit
// hole for now.

void swap(int v[], int i, int j) {
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void qsort(int v[], int left, int right) {
  int i, last;
 
  if (left >= right)
    return;
  swap(v, left, (left+right)/2);    // move partition elem to v[0]
  last = left;
  for (i = left+1; i <= right; i++) // partition
    if (v[i] < v[left])
      swap(v, ++last, i);
  swap(v, left, last);              // restore partition elem
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

int main() {
  int v[] = { 17, 2, 14, 6, -1, 0 };
  qsort(v, 0, 5);
}
