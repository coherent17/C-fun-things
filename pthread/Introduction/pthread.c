#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *myturn(void *arg){
	for(int i = 0; i < 8; i++){
		sleep(1);
		printf("My Turn! %d\n", i);
	}
	return NULL;
}

void yourturn(){
	for(int i = 0; i < 3; i++){
		sleep(2);
		printf("Your Turn! %d\n", i);
	}
}


int main(){
	pthread_t newthread;

	pthread_create(&newthread, NULL, myturn, NULL);
	yourturn();

	//wait until the thread is done before we exit.
	pthread_join(newthread, NULL);
	return 0;
}