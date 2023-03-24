# Append Node in linkedlist
## Method 1
```c
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
```

In this method, there exist 2 cases for appending the node
*   1. append the head node
*   2. append in the tail

## Method 2
```c
void appendNode2(int value, Node **headptr){
    Node *newNode = createNode(value);
    Node **indirect = headptr;
    while(*indirect){
        indirect = &((*indirect)->next);
    }
    *indirect = newNode;
}
```
By using the pointer point to the address that we want to change, we no longer need to evaluate whether the node is the first to append into the linkedlist or not.