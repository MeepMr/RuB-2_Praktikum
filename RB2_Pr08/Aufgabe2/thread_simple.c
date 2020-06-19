#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *zeige(void *arg);
void *schlafe (void *args);

int main (void)
{
	int status;
	int data[3];
	int len = sizeof(data) / sizeof(data[0]);
	pthread_t thread[len];
	char *buf[1];

	/* Starte den Thread */

	for(int i = 0; i < len; i++){

	    scanf("%d", &data[i]);
	}

	for(int i = 0; i<len; i++) {

        status=pthread_create(&thread[i],NULL,schlafe,&data[i]);
        if(status!=0){
            fprintf(stderr,"Error: Konnte Thread nicht erzeugen\n");
            exit(-1);
        }
	}

	/* Warte auf Terminierung */

	for(int i = 0; i < len; i++) {

        pthread_join(thread[i],NULL);
    }

	exit(0);
}

void *zeige(void *arg){

	int *dat = (int*)arg;

	printf("Habe folgende Daten erhalten %d\n",*dat);

	return NULL;
}

void *schlafe(void *arg) {

    int *sek = (int*) arg;

    printf("%d\n", *sek);
    sleep(*sek);
    printf("%d terminating\n", *sek);

    return NULL;
}
