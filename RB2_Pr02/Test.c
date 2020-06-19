#include <stdio.h>
#include <unistd.h>

int main() {

    printf("Guten %d\n", fork());
    printf("Tag %d\n", fork());

    return 1;
}
