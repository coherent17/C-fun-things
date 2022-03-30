#include <stdio.h>
#include <stdbool.h>

//the member store independently in different location
typedef struct{
	int x;
	float y;
	char z;
} mystruct;

//the whole member store in the same memory address, can save the memory space
typedef union{
	int x;
	float y;
	char z;
} myunion;

typedef struct{
	char *name;
	bool isrobot;
	union{
		char *personality;
		int robot_version;
	};
} character;

void print_character(character *c){
	printf("character: %s -- ", c->name);
	if(c->isrobot){
		printf("version %i", c->robot_version);
	}
	else{
		printf("%s", c->personality);
	}
	printf("\n");
}

int main(){

	mystruct s;
	s.x = 45;
	s.y = 9.87;
	s.z = 'H';

	myunion u;
	u.x = 45;
	u.y = 9.87;
	u.z = 'H';

	printf("size of struct: %lu\n", sizeof(mystruct)); 		//12
	printf("{%d %f %c}\n", s.x, s.y, s.z);					//{45 9.870000 H}

	printf("size of union: %lu\n", sizeof(myunion));		//4	
	printf("{%d %f %c}\n", u.x, u.y, u.z);					//{1092479816 9.869942 H}: overwrite issue


	character hansolo;
	character r2d2;
	hansolo.name = "Han Solo";
	hansolo.isrobot = false;
	hansolo.personality = "Scruffy-looking Nerfherder";

	r2d2.name = "R2";
	r2d2.isrobot = true;
	r2d2.robot_version = 42;

	print_character(&hansolo);
	print_character(&r2d2);

	return 0;
}