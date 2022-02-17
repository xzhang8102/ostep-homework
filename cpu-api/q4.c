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
    // execl("/bin/ls", "ls", "-G", NULL);
    // execle("/bin/ls", "ls", "-G", NULL, NULL);
    // execlp("ls", "ls", "-G", NULL);
    // execv("/bin/ls", (char *[]){"ls", "-G", NULL});
    execvp("ls", (char *[]){"ls", "-G", NULL});
  } else {
    wait(NULL);
  }
  return 0;
}
