#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

//bug number in unsigned long
#define BIG 1000000000UL
uint32_t counter = 0;

void *count_to_big(void *arg){
	for(uint32_t i = 0; i < BIG; i++){
		counter++;
	}
	return NULL;
}

//the race condition program, run slower and wrong
int main(){
	pthread_t t;
	pthread_create(&t, NULL, count_to_big, NULL);
	count_to_big(NULL);
	pthread_join(t, NULL);
	printf("Done. Counter = %u\n", counter);
	return 0;
}