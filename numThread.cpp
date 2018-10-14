#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define numT 5

void *funcao(void *threadid){
	long tid;
	tid = (long) threadid;
	printf("Ola thread numero %ld!\n", tid);
	pthread_exit(NULL);
}

int main(){
//	printf("Suponha que voce definiu o numero de threads, mas na verdade é 5\n");
	pthread_t thread[numT];
	int contador;
	long i;
	for (int i = 0; i < numT; i++){
		printf("Estou na main, criando a thread de número %ld\n", i);
		contador = pthread_create(&thread[i], NULL, *funcao, (void *) i);
	}
}
//Neste código, são printadas 5 vezes "estou no main" e "ola thread X", 0 =< X < 5
