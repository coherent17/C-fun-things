#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 25000

int main(int argc, char **argv){
    
    if(argc < 2){
        printf("usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if(!fp){
        perror("fopen error");  //output the error message to stderr
        return EXIT_FAILURE;
    }

    char buffer[BUFSIZE];
    int ret = fread(buffer, sizeof(char), BUFSIZE, fp);
    fclose(fp);

    if(ret > 0){
        printf("Got %d bytes\n", ret);
    }

    else{
        printf("READ FAILED!\n");
    }

    return 0;
}