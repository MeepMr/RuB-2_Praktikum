#include <unistd.h>
#include <ctype.h>

int main(void) {

    char sStr [1];

    while (read(STDIN_FILENO, sStr, 1)){

        sStr [0] = toupper(sStr[0]);
        write(STDOUT_FILENO, sStr, 1);
    }

  return 0;
}
