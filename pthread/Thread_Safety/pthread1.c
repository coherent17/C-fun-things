#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

//bug number in unsigned long
#define BIG 1000000000UL
uint32_t counter = 0;

void count_to_big(){
	for(uint32_t i = 0; i < BIG; i++){
		counter++;
	}
}

int main(){
	count_to_big();
	count_to_big();
	printf("Done. Counter = %u\n", counter);
	return 0;
}