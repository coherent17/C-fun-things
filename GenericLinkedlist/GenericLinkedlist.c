#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	void *data;          //the void pointer can accept any data type
	struct _node *next;
} node;


//the self define data should be able to be a node of the linkedlist
typedef struct _test{
	int a;
	char b;
} test;


node *createNode(void *data){
	node *newnode = malloc(sizeof(node));
	newnode->data = malloc(sizeof(data));

	//copy the self define data into the node of the linkedlist
	for(int i = 0; i < sizeof(data); i++){
		*(char *)(newnode->data + i) = *(char *)(data + i);
	}

	newnode->next = NULL;
	return newnode;
}

//push the node in the head of the linkedlist
void push(node **head, void *data){
	node *newnode = createNode(data);
	newnode->next = *head;
	*head = newnode;
}

//print out the linkedlist
void printLinkedlist(node *head){
	node *temp = head;
	while(temp){
		//when dereference the void pointer, need to tranfer the type first
		printf("%d %c -> ", ((test *)(temp->data))->a, ((test *)temp->data)->b);
		temp = temp->next;
	}
	printf("\n");
}

void freeLinkedlist(node *head){
	node *temp;
	while(head != NULL){
		temp = head;
		head = head->next;
		free((temp->data));
		free(temp);
	}
}

int main(){
	node *head = NULL;

	test data1 = {.a = 1, .b = 'a'};
	test data2 = {.a = 2, .b = 'b'};
	test data3 = {.a = 3, .b = 'c'};
	test data4 = {.a = 4, .b = 'd'};

	push(&head, &data1);
	push(&head, &data2);
	push(&head, &data3);
	push(&head, &data4);
	printLinkedlist(head);
	freeLinkedlist(head);
	return 0;
}