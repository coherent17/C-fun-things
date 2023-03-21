#include "mycode.h"
#include <string.h>

char *reverse(char *string){
    int len = strlen(string);
    for(int i = 0; i < len / 2; i++){
        char temp = string[i];
        string[i] = string[len-i-1];
        string[len-i-1] = temp;
    }
    return string;
}
