#include <stdio.h>
#include <string.h>

void to_upper_case(char in[], char out[]){

    for(int i = 0; i < strlen(in); i++){

        if((in[i] > 96) && in[i] < 123){

            out[i] = in[i] - 32;
        } else {

            out[i] = in[i];
        }
    }
}

void main(void){

    char input[30] = "a-6430 ötztal-bahnhof";
    char output[30];

    printf("Original:      %s\n", input);

    to_upper_case(input, output);

    printf("Umgewandelt:   %s\n", output);
}