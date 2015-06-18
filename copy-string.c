#include <stdio.h>
#include <string.h>

// strcat concatenates its second argument to the memory in first, so if we
// haven't allocated memory in the first we are trying to write to memory we
// don't own. Also note that strcat should probably not be used directly, but we
// would normally use strlcat or strncat to make buffer overflows harder, AIUI.

// I don't know why I didn't get any errors on Ubuntu. Also, is there not a
// nicer way to do this? A functional strccat that allocates new memory,
// perhaps? Considering we don't know second argument's size when we declare the
// first. Anyway, this will do for now.

int main() {
  char foo[100] = "foo";
  strcat(foo, "bar");
  printf("this: %s\n", foo);
}
