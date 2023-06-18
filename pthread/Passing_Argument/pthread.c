#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *myturn(void *arg){
	//casting the passing argument from pthread_create
	int *vptr = (int *)arg;

	for(int i = 0; i < 8; i++){
		sleep(1);
		printf("My Turn! %d, v = %d\n", i, *vptr);
		(*vptr)++;
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
	int v = 5;

	//passing the int v to the function by pointer
	pthread_create(&newthread, NULL, myturn, &v);
	yourturn();

	//wait until the thread is done before we exit.
	pthread_join(newthread, NULL);
	printf("thread is finished in v = %d\n", v);
	return 0;
}