#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int x = 100;
  int id = fork();
  if (id < 0) {
    perror("fork");
    exit(1);
  } else if (id == 0) {
    x = x + 1;
    printf("Child: x = %d\n", x);
  } else {
    x = x - 1;
    printf("Parent: x = %d\n", x);
  }
}