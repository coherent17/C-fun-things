#include <stdio.h>
#include <unistd.h>

int main(){

    //if fork return 0, then the process is the child process
    //else fork return child pid, so that can keep and eye on child process 

    if(fork() == 0){
        printf("I am child process! \n");

        //let child process run command
        execlp("ls", "ls", "-al", NULL);    //variadic function terminated with NULL 
        printf("Finish execlp!\n");
    }
    else{
        printf("I am parent process! %d\n", getpid());
    }
    
    return 0;
}