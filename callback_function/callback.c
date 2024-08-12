#include <stdio.h>
#include <stdlib.h>

// pass a callback function pointer to the add that takes a int as the argument
int add(int a, int b, void (*print_callback)(int)){
	int sum = a + b;
	print_callback(sum);
	return sum;
}

void conole_print(int value){
	printf("%d\n", value);
}

void file_print(int value){
	FILE *fp = fopen("tmp.txt", "w");
	fprintf(fp, "%d", value);
	fclose(fp);
}

int main(){
	// print the output to console
	add(10, 20, conole_print);

	// print the output to file
	add(10, 20, file_print);
	return 0;
}
