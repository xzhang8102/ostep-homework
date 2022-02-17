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
    // int w = wait(NULL);
    // returns [ECHILD]
    printf("Hello from child.\n");
  } else {
    // wait returns child pid
    // int w = wait(NULL);
    printf("Hello from parent.\n");
  }
  return 0;
}
