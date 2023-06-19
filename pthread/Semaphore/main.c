#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t s;

void *foo(void *arg){

    //wait (P)
    sem_wait(&s);
    printf("Enter critical section\n");

    //critical section
    sleep(4);

    //signal (V)
    printf("Ready to Exiting\n");
    sem_post(&s);
    return NULL;
}

int main(){
    
    //init the semaphore
    sem_init(&s, 0, 1);

    pthread_t t1, t2;
    pthread_create(&t1, NULL, foo, NULL);
    sleep(2);
    pthread_create(&t2, NULL, foo, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);;
    sem_destroy(&s);
    return 0;
}