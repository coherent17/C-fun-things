#include <stdio.h>
#include <stdint.h>

struct counters{
    int little : 2;
    int medium : 4;
    int large : 6;
}__attribute__((packed));

#define NUM_LOOP 50

int main(){
    //init the struct
    struct counters count;
    count.little = 0;
    count.medium = 0;
    count.large = 0;

    for (int i = 0; i < NUM_LOOP;i++){
        count.little++;
        count.medium++;
        count.large++;
        printf("%d %d %d\n", count.little, count.medium, count.large);
    }
    printf("sizeof count = %ld\n", sizeof(struct counters));
    return 0;
}