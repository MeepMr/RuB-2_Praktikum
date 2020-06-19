#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *zeige(void *arg);
void *schlafe (void *args);

int main (void)
{
	int status;
	int data=3;
	pthread_t thread;

	/* Starte den Thread */

	status=pthread_create(&thread,NULL,schlafe,&data);
	if(status!=0){
		fprintf(stderr,"Error: Konnte Thread nicht erzeugen\n");
		exit(-1);		
	}



	/* Warte auf Terminierung */
	pthread_join(thread,NULL);

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
    printf("terminating\n");

    return NULL;
}
