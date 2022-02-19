#include <stdio.h>
#include <unistd.h>

const int PRO_BAR_LENGTH = 100;

/*
"\r"
When writing to an interactive terminal on stdout or stderr,
'\r' can be used to move the cursor back to the beginning of the line,
to overwrite it with new contents. This makes a nice primitive progress indicator.
*/

void update_bar(int percent_done){
	int num_char = percent_done * PRO_BAR_LENGTH / 100;
	printf("\r[");
	for(int i = 0; i < num_char; i++){
		printf("#");
	}
	for(int i = 0; i < PRO_BAR_LENGTH - num_char; i++){
		printf(" ");
	}
	printf("] %d%% Done", percent_done);
	fflush(stdout);
}

int main(){
	for(int i = 0; i <= 100; i++){
		update_bar(i);
		usleep(20000);
	}
	printf("\n");
}