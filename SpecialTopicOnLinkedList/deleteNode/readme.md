# Delete Node in linkedlist
## Method 1
```c
void deleteNode1(List *list, Node *target){
    Node *prev = NULL;
    Node *curr = list->head;

    while(curr != target){
        prev = curr;
        curr = curr->next;
    }

    if(!prev) 
        list->head = target->next;
    else
        prev->next = target->next;
}
```

In this method, there exist 2 cases for deleting the node:
*   1. delete the head node
*   2. delete the node except for the head node

## Method 2
```c
void deleteNode2(List *list, Node *target){
    Node **indirect = &list->head;
    while(*indirect != target)
        indirect = &(*indirect)->next;
    *indirect = target->next;
}
```
By using the pointer point to the address that we want to change, we no longer need to evaluate whether the node want to delete is head node or others.

## What I learn:
*   Linus Torvalds: Sometimes you can see a problem in a different way and rewrite it so that a special case goes away and becomes the normal case. And that’s good code. 