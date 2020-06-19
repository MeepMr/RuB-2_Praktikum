#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler (int signo){

    if(signo == SIGINT) {

        printf("SIGINT empfangen\n");
    } else if(signo == SIGTERM) {

        printf("SIGTERM empfangen\n %d", signo);
        printf("%s", SIGTERM)
    } else {

        printf("error");
    }
}

int main(void) {

  if(signal(SIGINT, sig_handler) == SIG_ERR){
    perror("SIGINT fehler\n");
    exit(1);
  }

  if(signal(SIGTERM, sig_handler) == SIG_ERR){
      perror("SIGTERM fehler\n");
      exit(1);
  }

  for ( ; ; ) {
    pause();
    puts("main: Signal empfangen");
  }
}
