#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static Node *createNode(int value){
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

List *createList(){
    List *newList = malloc(sizeof(List));
    newList->head = NULL;
    return newList;
}

void printList(List *list){
    Node *temp = list->head;
    while(temp != NULL){
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void addNode(List *list, int value){
    Node *newnode = createNode(value);
    newnode->next = list->head;
    list->head = newnode;
}

Node *findNode(List *list, int value){
    Node *temp = list->head;
    while(temp->value != value)
        temp = temp->next;
    return temp;
}

//intuition delete node method
void deleteNode1(List *list, Node *target){
    Node *prev = NULL;
    Node *curr = list->head;

    while(curr != target){
        prev = curr;
        curr = curr->next;
    }

    //2 cases here, remove the head node or the middle node
    if(!prev) 
        list->head = target->next;
    else
        prev->next = target->next;
}

//better taste for delete node
void deleteNode2(List *list, Node *target){
    // The indirect pointer point to the address that we'll update
    Node **indirect = &list->head;
    while(*indirect != target)
        indirect = &(*indirect)->next;
    *indirect = target->next;
}