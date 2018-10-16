#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define num 5

int posicao = 0;

//Como criar mutex
pthread_mutex_t meuMutex = PTHREAD_MUTEX_INITIALIZER;

void *mostraThread(void *id){
	//As linhas abaixo são de uma região crítica com controle de acesso
	pthread_mutex_trylock(&meuMutex);
	posicao++;
	printf("Olá thread número %d\n",posicao);
	pthread_mutex_unlock(&meuMutex);
	pthread_exit(NULL);
}

int main(){
	long i = 0;
	pthread_t threads[num];
	
	for (i = 0; i < num; i++){
		pthread_create(&threads[i], NULL, mostraThread, NULL);
	}

	for (i = 0; i < num; i++){
		pthread_join(threads[i], NULL);
	}

	return 0;
}
//Este código printa, Olá thread número X, 0 < X < 6, fora de ordem
