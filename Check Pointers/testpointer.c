#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/errno.h>

int ismapped(const void *ptr, int bytes){
    if(ptr==NULL){
        return 0;
    }

    //create a pipe
    int fd[2];
    int valid = 1;

    pipe(fd);
    if(write(fd[1], ptr, bytes)<0){
        if(errno==EFAULT){
            valid = 0;
        }
    }
    close(fd[0]);
    close(fd[1]);
    return valid;
}

//don't care the type of pointer
void testptr(void *p, int bytes, char *name){
    printf("%s:\t%d\t%p\n", name, ismapped(p, bytes), p);
}

int main(){
    int *junk = NULL;
    int *junk2 = (int *)((intptr_t)0x35234524a);
    int *p = malloc(50);
    int x = 5;
    int *px = &x;

    testptr(junk, 1, "junk");
    testptr(junk2, 1, "junk2");
    testptr(px, sizeof(int), "px");
    testptr(p, 50, "p");

    return 0;
}