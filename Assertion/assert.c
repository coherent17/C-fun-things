#include <stdio.h>
#include <assert.h>

int main(){
	
	int i;

	printf("begin------\n");

	for(i = 0; i < 10; i++){
		printf("i = %d\n", i);
		assert(i <= 5);			//when i = 6, it will make assertion
		//compile with -DNDEBUG can ignore the assert!
	}

	printf("end--------\n");
	return 0;
}