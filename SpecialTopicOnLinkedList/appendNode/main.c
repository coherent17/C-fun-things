#include "list.h"
#include <stdlib.h>

int main(){
    Node *head1 = NULL;
    for(int i = 0; i < 10; i++){
        appendNode1(i, &head1);
    }
    printList(head1);

    Node *head2 = NULL;
    for(int i = 0; i < 10; i++){
        appendNode2(i, &head2);
    }
    printList(head2);
    return 0;
}