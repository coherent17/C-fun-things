#include <stdio.h>
#include <stdlib.h>
#include <aio.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

#define BUFSIZE 25000

struct aiocb *async_read(FILE *fp, char *buf, int bytes){
    struct aiocb *aio = malloc(sizeof(struct aiocb));
    if(!aio) return NULL;

    memset(aio, 0, sizeof(*aio));
    aio->aio_buf = buf;
    aio->aio_fildes = fileno(fp);
    aio->aio_nbytes = bytes;
    aio->aio_offset = 0;

    int result = aio_read(aio);
    if(result < 0){
        free(aio);
        return NULL;
    }

    return aio;
}

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
    //aiocb: asynchronousIO_control_block
    struct aiocb* aio = async_read(fp, buffer, BUFSIZE);
    uint64_t counter = 0;
    while(aio_error(aio) == EINPROGRESS){
        counter++;
    }

    int ret = aio_return(aio);
    
    fclose(fp);

    printf("Count up %lu times while reading\n", counter);

    if(ret > 0){
        printf("Got %d bytes\n", ret);
    }

    else{
        printf("READ FAILED!\n");
    }

    return 0;
}