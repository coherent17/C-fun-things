#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

//bug number in unsigned long
#define BIG 1000000000UL
uint32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *count_to_big(void *arg){
	for(uint32_t i = 0; i < BIG; i++){
		//make things atomic
		pthread_mutex_lock(&lock);		//other thread will wait here until it can get the lock
		counter++;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

//using mutex to solve the race condition issue
int main(){
	pthread_t t;
	pthread_create(&t, NULL, count_to_big, NULL);
	count_to_big(NULL);
	pthread_join(t, NULL);
	printf("Done. Counter = %u\n", counter);
	return 0;
}