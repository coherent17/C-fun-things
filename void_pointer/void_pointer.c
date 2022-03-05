#include <stdio.h>
#include <stdlib.h>

int main(){
	int a = 10;
	void *ptr = &a;

	//try to dereference the void pointer:
	//warning: dereferencing ‘void *’ pointer
	//printf("%d\n", *ptr);

	//need to tranform to integer pointer then dereference
	printf("%d\n", *(int *)ptr);
	return 0;
}