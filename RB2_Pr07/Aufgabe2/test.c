#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 4096

int main(int argc, char *argv[]) {
    int fifoA, fifoB;
    char text[MAXLINE];

    //Text von Commandline
    if (argc >= 2) {
        puts("Found Argument");
        for (int i = 0; i < strlen(argv[1]); i++) {
            text[i] = argv[1][i];
        }
    }

    //Paths
    char *fifoA_path = "/home/mrmeep/fifoA";
    char *fifoB_path = "/home/mrmeep/fifoB";

    //Fifos öffnen
    fifoA = open(fifoA_path, O_WRONLY);
    fifoB = open(fifoB_path, O_RDONLY);
    puts("Opened Fifos");

    int test = write(fifoA, text, strlen(text));
    close(fifoA);

    //Sleep
    sleep(3);

    //lese ergebnis
    char erg[MAXLINE];
    while (read(fifoB, erg, MAXLINE)) {
        printf("%s\n", erg);
    }

    //FifoB schließen
    close(fifoB);

}2