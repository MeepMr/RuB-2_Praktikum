#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 4096

int main(int argc, char **argv) {
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

      write(A[1], argv[1], strlen(argv[1]));
      n = read(B[0], line, MAXLINE);
      printf("%s", line);
  }
  else {                        /* child */

      char strg [MAXLINE];
      close(A[1]);
      close(B[0]);

      n = read(A[0], line, MAXLINE);
      sleep(0);

      for(int i = 0; i < n; i++){

          strg[i] = toupper(line[i]);
      }

      write(B[1], strg, n);
      exit(0);
  }
  wait(NULL);

  return 0;
}
