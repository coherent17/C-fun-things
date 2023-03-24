#ifndef _LIST_H_
#define _LIST_H_

typedef struct _Node{
    int value;
    struct _Node *next;
}Node;

void printList(Node *head);
void appendNode1(int value, Node **headptr);
void appendNode2(int value, Node **headptr);
#endif