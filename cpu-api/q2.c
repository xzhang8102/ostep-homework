#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Write a program that opens a file (with the open() system call)
 * and then calls fork() to create a new process. Can both the child
 * and parent access the file descriptor returned by open()? What
 * happens when they are writing to the file concurrently, i.e., at the
 * same time? 
 */
int main(int argc, char const *argv[])
{
  int fd = open("./q2.output", O_RDWR | O_CREAT, 0644);
  int pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  } else if (pid == 0) {
    // child
    printf("fd from child: %d\n", fd);
    write(fd, "hello from child!\n", 18);
  } else {
    // parent
    printf("fd from parent: %d\n", fd);
    write(fd, "hello from parent\n", 18);
  }
}
