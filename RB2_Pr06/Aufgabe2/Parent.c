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
    char writex [MAXLINE];
    argv[1] = "Test";

    for(int i = 0; i < strlen(argv[1]); i++){

        writex [i] = argv[1] [i];
    }

    int lgt = strlen(writex);

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

        write(A[1], writex, lgt);
        read(B[0], line, lgt);
        printf("%s", line);
    }
    else {                        /* child */

        close(A[1]);
        close(B[0]);

        dup2(A[0], STDIN_FILENO);
        dup2(B[1], STDOUT_FILENO);

        printf("%d", execlp("/home/mrmeep/CLionProjects/RB2_Praktikum/RB2_Pr06/Aufgabe1/toUpper.sh", "toUpper.sh", NULL));
    }
    wait(NULL);

    return 0;
}
