#include <stdio.h>
#include <unistd.h>


int main (void) {

    int fd [2];
    int err = pipe(fd);
    int strgLgt;
    char strg [4096];
    if(err < 0) { perror("pipe error"); _exit(1);}

    write(fd[1],"Hello World", 13);
    strgLgt = read(fd[0], strg, 4096);
    printf("%s", strg);


    return 0;
}
