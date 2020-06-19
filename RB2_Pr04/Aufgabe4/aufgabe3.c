#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAXLINE 4096	/* max line length */

void signal_handler(int signr){

    if(signr == SIGINT){

        printf("Strg + C funktioniert nicht\n");
    } else if(signr == SIGTERM) {

        printf("Bye");
        exit(SIGTERM);
    } else if(signr == SIGCHLD){

        while (waitpid(-1,NULL,WNOHANG));
    }
}

int main(void) {
  char	buf[MAXLINE];
  pid_t   pid;
  int		status;
  int background = 0;

  if(signal(SIGINT, signal_handler)){

      perror("Error Catching SIGINT\n");
  }

  if (signal(SIGTERM, signal_handler)){

    perror("Error Catching SIGTERM\n");
  }

  if(signal(SIGCHLD, signal_handler)){

    perror("Error catching SIGCHLD\n");
  }

  printf("%% ");  /* print prompt (printf requires %% to print %) */
  while (fgets(buf, MAXLINE, stdin) != NULL) {
    buf[strlen(buf) - 1] = 0;	/* replace newline with null */

    background = 0;
    if((buf[0] == 'q') && (strlen(buf) == 1)){
        exit(1);
    } else if (buf[strlen(buf) -1] == '&'){

        buf[strlen(buf) -2] = '\0';
        background = WNOHANG;
    }

    if ( (pid = fork()) < 0)
      perror("fork error");
    
    else if (pid == 0) {		/* child */
      execlp(buf, buf, (char *) 0);
      printf("couldn't execute: %s\n", buf); 
      exit(127);
    }

    /* parent */
    if ( (pid = waitpid(pid, &status, background)) < 0)
      perror("waitpid error"); 
    printf("%% ");
  }
  exit(0);
}
