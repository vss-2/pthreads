#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *printar (void *ptr){
	char *msg;
	msg = (char *) ptr;
	printf("%s \n", msg);
}

int main (){
	pthread_t thread1, thread2;
	char msg1[] = "Thread1";
	char msg2[] = "Thread2";
	int ret1, ret2;
	
	//Cria threads independentes, e cada uma vai executar funções distintas

	ret1 = pthread_create(&thread1, NULL, *printar, (void *)msg1);
	ret2 = pthread_create(&thread2, NULL, *printar, (void *)msg2);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Thread 1 respondeu: %d\n", ret1);
	printf("Thread 2 respondeu: %d\n", ret2);
}
