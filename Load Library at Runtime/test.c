#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char **argv){

    if(argc < 3){
        printf("usage: %s <library> <number>\n", argv[0]);
        exit(1);
    }

    char *librarypath = argv[1];
    int number = atoi(argv[2]);


    //using dlopen to open the library, with flag lazy loading
    //when the function are going to be loaded when trying to use it
    void *libhandle = dlopen(librarypath, RTLD_LAZY);

    if(libhandle == NULL){
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }


    int (*opfunc)(int);
    opfunc = dlsym(libhandle, "do_operation");

    char *(*libnamefunc)();
    libnamefunc = dlsym(libhandle, "get_library_name");

    //if no that function then dlsym return NULL
    if(opfunc == NULL || libnamefunc == NULL){
        printf("ERROR: could not read functions from library.\n");
        exit(1);
    }

    printf("Library: %s\n", libnamefunc());
    printf("%d --> %d\n", number, opfunc(number));

    //close the library
    dlclose(libhandle);
}