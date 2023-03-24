#ifndef _LIST_H_
#define _LIST_H_

typedef struct _Node{
    int value;
    struct _Node *next;
}Node;

typedef struct _List{
    Node *head;
}List;

List *createList();
void printList(List *list);
void addNode(List *list, int value);
Node *findNode(List *list, int value);
void deleteNode1(List *list, Node *target);
void deleteNode2(List *list, Node *target);
#endif