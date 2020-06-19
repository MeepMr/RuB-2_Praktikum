#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {

    mkfifo("/etc/fifo1", O_RDWR);
    mkfifo("/etc/fifo2", O_RDWR);

    int fifoA;
    int fifoB;
    char sTest [1];
    char sText = "Hallo Welt";

        fifoA = open("/etc/fifo1", O_WRONLY);
        fifoB = open("/etc/fifo2", O_RDONLY);
        puts("FiFos opened");
        write(fifoA, sText, 12);
        close(fifoA);


       while(read(fifoB, sTest,1)) {

           printf("%s\n", sTest);
       }

       close(fifoB);



  return 0;
}
