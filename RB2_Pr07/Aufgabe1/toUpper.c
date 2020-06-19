#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {

    char sStr [1];
    mkfifo("/etc/fifo1", 0666);
    mkfifo("/etc/fifo2", 0666);

    int fifoA;
    int fifoB;

    while (1) {

        fifoA = open("/home/mrmeep/fifoA", O_RDONLY);
        fifoB = open("/home/mrmeep/fifoB", O_WRONLY);
        puts("Fifo open");
        char sStr [1];

        while (read(fifoA, sStr, 1)) {

            sStr[0] = toupper(sStr[0]);
            puts(sStr);
            write(fifoB, sStr, 1);
        }
        close(fifoA);
        close(fifoB);
    }


  return 0;
}
