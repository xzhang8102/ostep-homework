#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Write another program using fork(). The child process should
 * print “hello”; the parent process should print “goodbye”. You should
 * try to ensure that the child process always prints first without calling wait()
 * in the parent?
 */
int main(int argc, char *argv[])
{
  // more info about fork and pipe: https://stackoverflow.com/questions/4812891/fork-and-pipes-in-c
  int pipefd[2];
  if (pipe(pipefd) == -1) {
    perror("pipe");
    exit(1);
  }
  printf("Before fork: this message is expected to appear once.\n");
  int pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  } else if (pid == 0) {
    close(pipefd[0]);
    FILE *stream = fdopen(pipefd[1], "w");
    fprintf(stream, "Done");
    fclose(stream);
    printf("hello\n");
  } else {
    close(pipefd[1]);
    FILE *stream = fdopen(pipefd[0], "r");
    while(fgetc(stream) != EOF);
    fclose(stream);
    printf("goodbye\n");
  }
}
