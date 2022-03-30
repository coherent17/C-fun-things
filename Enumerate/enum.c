#include <stdio.h>

enum day{
	Mon = 1,
	Tue = 2,
	Wed = 3,
	Thu = 4,
	Fri = 5,
	Sat = 6,
	Sun = 7
};

void judge_weekend(int date){
	if(date == Sat || date == Sun){
		printf("It's weeked!\n");
	}
	else printf("Not a weekend!\n");
}

int main(){

	enum day today = Sat;
	enum day yesterday = Fri;
	judge_weekend(today);
	judge_weekend(yesterday);
	return 0;
}