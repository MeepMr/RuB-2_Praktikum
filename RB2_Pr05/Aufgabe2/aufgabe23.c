#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#define MAXLINE 4096

int main(void) {
  int   n, A[2], B[2], err;
  pid_t pid;
  char  line[MAXLINE];
  
  err = pipe(A);
  if (err < 0) {
    perror("pipe error");
    exit(1);
  }

    err = pipe(B);
    if (err < 0) {
        perror("pipe error");
        exit(1);
    }

  pid = fork();
  if (pid < 0) {
    perror("fork error");
    exit(1);
  }     
  
  else if (pid > 0) {           /* parent */

      close(B[1]);
      close(A[0]);

      write(A[1], "TestNachricht", MAXLINE);
      n = read(B[0], line, MAXLINE);
      printf("%s", line);
  }
  else {                        /* child */

      close(A[1]);
      close(B[0]);

      n = read(A[0], line, MAXLINE);
      sleep(1);
      write(B[1], line, n);
      exit(0);
  }
  wait(NULL);
  return 0;
}
