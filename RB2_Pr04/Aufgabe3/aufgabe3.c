#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAXLINE 4096	/* max line length */

int main(void) {
  char	buf[MAXLINE];
  pid_t   pid;
  int		status;
  
  printf("%% ");  /* print prompt (printf requires %% to print %) */
  while (fgets(buf, MAXLINE, stdin) != NULL) {
    buf[strlen(buf) - 1] = 0;	/* replace newline with null */

    if((buf[0] == 'q') && (strlen(buf) == 1)){
        exit(1);
    }

    if ( (pid = fork()) < 0)
      perror("fork error");
    
    else if (pid == 0) {		/* child */
      execlp(buf, buf, (char *) 0);
      printf("couldn't execute: %s\n", buf); 
      exit(127);
    }

    /* parent */
    if ( (pid = waitpid(pid, &status, 0)) < 0)
      perror("waitpid error"); 
    printf("%% ");
  }
  exit(0);
}
