#include <stdio.h>
#include <string.h>
#include <uuid/uuid.h>

#define UUIDTEXTSIZE (sizeof(uuid_t) * 2) + 5

void print_raw_uuid(uuid_t id){
    printf("RAW: ");
    for(int i = 0; i < sizeof(uuid_t); i++){
        printf("%x ", id[i]);   //print in lower-case hexadecimal
    }
    printf("\n");
}

int main(){

    char uuidtext[UUIDTEXTSIZE];

    //random base uuid
    uuid_t random_uuid;          //char []
    uuid_generate(random_uuid);  //passing the pointer of the char array
    print_raw_uuid(random_uuid);
    uuid_unparse(random_uuid, uuidtext);     //format uuid into 8-4-4-4-12
    printf("UUID: %s\n", uuidtext);


    //time base uuid
    uuid_t time_uuid;
    uuid_generate_time(time_uuid);
    print_raw_uuid(time_uuid);
    uuid_unparse(time_uuid, uuidtext);
    printf("UUID: %s\n", uuidtext);


    uuid_t namespace_uuid;
    uuid_t name_uuid;
    uuid_parse("5b9776e2-1ac3-11ed-8701-ac1f6b40115a", namespace_uuid);
    uuid_generate_md5(name_uuid, namespace_uuid, "Coherent", strlen("Coherent"));
    uuid_unparse(name_uuid, uuidtext);
    printf("UUID: %s\n", uuidtext);

    return 0;
}