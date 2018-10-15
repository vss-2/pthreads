#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define num 5

int posicao = 0;

void *mostrarThread (void *id){
	//As linhas abaixo são uma região crítica sem controle de acesso

	posicao++;
	printf("Olá da thread: %d\n", posicao);
	
	pthread_exit(NULL);
}

int main(){
	long i = 0;
	pthread_t thread[num];
	
	for(i = 0; i < 5; i++){
		pthread_create(&thread[i], NULL, mostrarThread, NULL);
	}

	for (i = 0; i < 5; i++){
		pthread_join(thread[i], NULL);
	}
	return 0;
}
