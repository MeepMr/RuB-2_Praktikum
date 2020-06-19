#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main () {

    sleep(3);
    int pid = getpid();
    kill(pid,SIGTERM);
    return 1;
}