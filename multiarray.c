#include <stdio.h>

#define SYS_fork 1
#define SYS_exit 2

int sys_fork(void) { return 0; }
int sys_exit(void) { return 0; }

static int (*syscalls[])(void) = {
[SYS_fork] = sys_fork,
[SYS_exit] = sys_exit
};

// need = for this (newer) version of gcc
static char (*syscall_names[]) = {
  [SYS_fork] = "fork",
  [SYS_exit] = "exit"
};


int main() {
  printf("hello\n");
  printf("syscall: %s\n", syscall_names[SYS_fork]);
}
