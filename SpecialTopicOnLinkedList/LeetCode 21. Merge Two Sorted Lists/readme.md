# Merge 2 Sorted Lists

## Method 1:
*   Allocate a new node "head" and append the smaller node after head, return head->next
```c
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *temp = head;
    while(list1 && list2){
        if(list1->val <= list2->val){
            temp->next = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    temp->next = list1 ? list1 : list2;
    return head->next;
}
```

## Method 2
*   Using indirect pointer to avoid allocate memory for head
```c
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *head;
    struct ListNode **temp = &head;
    while(list1 && list2){
        if(list1->val <= list2->val){
            *temp = list1;
            list1 = list1->next;
        }
        else{
            *temp = list2;
            list2 = list2->next;
        }
        temp = &((*temp)->next);
    }
    *temp = list1 ? list1 : list2;
    return head;
}
```

## Method 3
*   Using another pointer to store which list go to the next
```c
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *head, **temp = &head, **node;
    while(list1 && list2){
        node = (list1->val <= list2->val) ? &list1 : &list2;
        *temp = *node;
        *node = (*node)->next;
        temp = &((*temp)->next);
    }
    *temp = list1 ? list1 : list2;
    return head;
}
```