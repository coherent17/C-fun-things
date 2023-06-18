#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
    if(argc < 2){
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    //using realpath function to return the allocated char array for the real path
    char *fullpath = realpath(argv[1], NULL);
    printf("ABS PATH: %s\n", fullpath);
    return 0;
}