#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *myturn(void *arg){
	int *ret = (int *)malloc(sizeof(int));
	*ret = 5;

	for(int i = 0; i < 8; i++){
		sleep(1);
		printf("My Turn! %d, result = %d\n", i, *ret);
		(*ret)++;
	}
	return ret;
}

void yourturn(){
	for(int i = 0; i < 3; i++){
		sleep(2);
		printf("Your Turn! %d\n", i);
	}
}


int main(){
	pthread_t newthread;
	int *result;

	//thread allocate memory and return to main
	pthread_create(&newthread, NULL, myturn, NULL);
	yourturn();

	//what thread join does?
	//1. wait until the thread is done before exit/
	//2. get the return value from thread
	pthread_join(newthread, (void *)&result);
	printf("thread is finished in result = %d\n", *result);
	return 0;
}