#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
  int pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  } else if (pid == 0) {
    close(STDOUT_FILENO);
    printf("Hello from child (%d).\n", getpid());
  } else {
    wait(NULL);
  }
}
