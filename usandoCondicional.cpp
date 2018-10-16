#include <pthread.h>
#include <stdio.h>

#define numtred 10
#define obstred 12

int contador = 0;
int conta = 0;

pthread_mutex_t contador_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t contador_limite = PTHREAD_COND_INITIALIZER;

int tredis[3] = {0, 1, 2};

void incrementarcontador (int *idp){
	for (int g = 0; g < numtred; g++){
		pthread_mutex_lock(&contador_mutex);
		conta++;
		printf("Incrementando: Thread %d, antes %d,\n novo contador %d\n", *idp, conta-1, conta);
		if (conta == obstred){
			pthread_cond_signal(&contador_limite);
		}
		pthread_mutex_unlock(&contador_mutex);
	}
}


void verConta(int *idp){
	pthread_mutex_lock(&contador_mutex);
	while (conta <= obstred){
		pthread_cond_wait(&contador_limite, &contador_mutex);
		printf("Ver contador: Thread %d, contador está %d\n", *idp, conta);
	}
	pthread_mutex_unlock(&contador_mutex);
}

extern int
main(void){
	pthread_t tredz[3];
	pthread_create(&tredz[0], NULL, incrementarcontador, &tredis[0]);
	pthread_create(&tredz[1], NULL, incrementarcontador, &tredis[1]);
	pthread_create(&tredz[2], NULL, incrementarcontador, &tredis[2]);

	for (int i = 0; i < 3; i++){
		pthread_join(tredz[i], NULL);
	}

	return 0;
}
