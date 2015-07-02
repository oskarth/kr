// Compile as follows to get all warnings and report as errors
// gcc -Werror -Wall unused.c

int main() {
  int foo;
  (void)foo; // without this we get an error
  return 0;
}
