#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static Node *createNode(int value){
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void printList(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void appendNode1(int value, Node **headptr){

    Node *newNode = createNode(value);
    Node *prev = NULL;
    Node *curr = *headptr;

    while(curr){
        prev = curr;
        curr = curr->next;
    }
    
    if(!prev) 
        *headptr = newNode;
    else
        prev->next = newNode;
}

void appendNode2(int value, Node **headptr){

    Node *newNode = createNode(value);

    Node **indirect = headptr;
    while(*indirect){
        indirect = &((*indirect)->next);
    }
    *indirect = newNode;
}