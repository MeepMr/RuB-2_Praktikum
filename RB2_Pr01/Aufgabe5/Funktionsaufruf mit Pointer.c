#include <stdlib.h>
#include <stdio.h>

void quadrat(float*);

void main(void){

    float laenge = 5.0;

    quadrat(&laenge);

    printf("Laenge: %f", laenge);
}

void quadrat (float *zahl){

    *zahl = *zahl * *zahl;
}