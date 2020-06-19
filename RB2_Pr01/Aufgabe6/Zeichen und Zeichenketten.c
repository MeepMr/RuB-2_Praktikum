#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int intlgt(char *s){

   int cntr = 0;

   while(s[cntr] < 58 && s[cntr] > 47){

       cntr++;
   } 

return cntr;
}

int ascii2int(char *s){
   
    int zahl = 0;
    int lgt = intlgt(s);

    int exp, pow;

    for(int i = 0; i < lgt; i++){

        exp = lgt-i-1;

        pow = 1;
        
        for(int i = 0; i < exp; i++){

            pow = pow*10;
        }

        if(s[i]<58 && s[i] > 47){
            
            zahl += (s[i]- '0' ) * pow;
        }
    }

    return zahl;
}

void main(){

    char *zahl[] = {"45444", "44227 Dortmund", "01234"};

    for (int i = 0; i < sizeof(zahl) / sizeof(char *); i++)
    {
        printf("Der String '%s' ist als Integer darstellt '%d'\n",
               zahl[i], ascii2int(zahl[i]));
    }
}