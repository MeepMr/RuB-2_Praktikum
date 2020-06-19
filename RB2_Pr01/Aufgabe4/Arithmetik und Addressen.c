#include <stdio.h>
#include <stdlib.h>

int quersumme (int zahl){
    int x = 0;
    int y = zahl;

    while(y > 9) {
        x= x + (y%10);
        y = y /10;
    }
    
    x= x+y;

    return x;
}

void main(void){

    int x = 0;

    printf("Geben sie eine Zahl ein: ");
    scanf("%u", &x);

    printf("Quersumme von %d: %d/n", x, quersumme(x));
}