#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 5

//can't deal with the overlapping memory system, but is faster than memmove
void memcpy2(void *des, void *src, size_t bytes){
    char *d = des, *s = src;
    for(int i = 0; i < bytes; i++){
        d[i] = s[i];
    }
}

//[1, 2, 3, 4, 5], remove 3
//[_, 1, 2, 4, 5];
bool remove_element(int *array, int index_to_remove){
    if(index_to_remove < 0 || index_to_remove >= SIZE){
        return false;
    }
    memmove(array + 1, array, sizeof(int) * index_to_remove);
    array[0] = 0;
    return true;
}

void printArray(int *array){
    for(int i = 0; i < SIZE; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int array[] = {1, 2, 3, 4, 5};
    remove_element(array, 2);
    printArray(array);

    remove_element(array, 4);
    printArray(array);

    return 0;
}