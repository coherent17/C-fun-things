#include "list.h"

int main(){
    List *l = createList();
    for(int i = 0; i < 10; i++){
        addNode(l, i);
    }
    printList(l);
    deleteNode1(l, findNode(l, 9));
    printList(l);
    deleteNode2(l, findNode(l, 8));
    printList(l);
    return 0;
}