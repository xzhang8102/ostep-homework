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
    // wait returns [ECHILD]
    printf("Hello from child (%d).\n", getpid());
  } else {
    // wait returns child pid
    int w = waitpid(pid, NULL, 0);
    printf("pid: %d, wait returns %d.\n", getpid(), w);
  }
  return 0;
}
