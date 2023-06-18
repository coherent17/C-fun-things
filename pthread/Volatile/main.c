#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

volatile bool done = false;

void *foo(void *arg){
    sleep(1);
    done = true;
    return NULL;
}

int main(int argc, char **argv){
    
    pthread_t p;
    pthread_create(&p, NULL, foo, NULL);
    
    printf("Waiting ...\n");
    while(!done){};
    printf("Keep Going.\n");

    return 0;
}