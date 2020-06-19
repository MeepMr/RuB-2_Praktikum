#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 4096

int main(int argc, char* argv[]) {

    char towrite[MAXLINE];

    for (int i = 0; i < strlen(argv[1]); i++) {
        towrite[i] = argv[1][i];
    }

    int length = strlen(towrite);
    int fdA[2], fdB[2];
    pid_t pid;

    //Parent schreiben
    pipe(fdA);
    //Child schreiben
    pipe(fdB);

    pid = fork();

    if(pid == 0)
    {
        //schreiben schließen
        close(fdA[1]);
        //lesen schließen
        close(fdB[0]);

        sleep(1);
        dup2(fdB[1], STDOUT_FILENO);
        dup2(fdA[0], STDIN_FILENO);

        printf("%d", execlp("/home/mrmeep/CLionProjects/RB2_Praktikum/RB2_Pr06/Aufgabe1/toUpper.sh", "test.sh", NULL));
    }

    //lesen schließen
    close(fdA[0]);
    //schreiben schließen
    close(fdB[1]);

    write(fdA[1], towrite, length);

    char text[MAXLINE];
    read(fdB[0], text, length);

    //Pipes schließen
    close(fdA[1]);
    close(fdB[0]);

    printf("%s\n", text);

    wait(NULL);
}