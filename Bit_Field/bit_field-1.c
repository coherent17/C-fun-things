//using bitfield to not to force user to passing all of the arguments
//using bitwise or to passing the options
//using bitwise and to get the info of the bitfield

#include <stdio.h>
#include <stdint.h>

#define CASE_ONE    0b00000001
#define CASE_TWO    0b00000010
#define CASE_THREE  0b00000100
#define CASE_FOUR   0b00001000


//return the value of x^y
int power(int x, int y){
    int result = 1;
    for (int i = 0; i < y;i++){
        result *= x;
    }
    return result;
}

//print out the binary of the value
void printBinary(int8_t value){
    for (int i = 7; i >= 0;i--){
        int temp = power(2, i);
        if(temp<=value){
            printf("1");
            value -= temp;
        }
        else
            printf("0");
    }
    printf("\n");
}

//print out the option bitwise and the case process
void printAndResult(int8_t option){
    printf("option = ");
    printBinary(option);
    if(option & CASE_ONE){
        printf("CASE_ONE = ");
        printBinary(CASE_ONE);
        printf("option & CASE_ONE = ");
        printBinary(option & CASE_ONE);
    }
    if(option & CASE_TWO){
        printf("CASE_TWO = ");
        printBinary(CASE_TWO);
        printf("option & CASE_TWO = ");
        printBinary(option & CASE_TWO);
    }
    if(option & CASE_THREE){
        printf("CASE_THREE = ");
        printBinary(CASE_THREE);
        printf("option & CASE_THREE = ");
        printBinary(option & CASE_THREE);
    }
    if(option & CASE_FOUR){
        printf("CASE_FOUR = ");
        printBinary(CASE_FOUR);
        printf("option & CASE_FOUR = ");
        printBinary(option & CASE_FOUR);
    }
    printf("\n");
}

//using bitwise and to track whtat is the user's option
void loadCase(int8_t option){
    if(option & CASE_ONE)
        printf("Case 1 detected\n");
    if(option & CASE_TWO)
        printf("Case 2 detected\n");
    if(option & CASE_THREE)
        printf("Case 3 detected\n");
    if(option & CASE_FOUR)
        printf("Case 4 detected\n");
    printf("\n");
    printAndResult(option);
}

int main(){
    //test1:
    uint8_t option = 0b00001001;
    printf("test1:\n");
    loadCase(option);

    //test2:
    printf("test2:\n");
    loadCase(CASE_ONE | CASE_TWO);

    //test3:
    printf("test3:\n");
    loadCase(CASE_ONE | CASE_TWO | CASE_THREE | CASE_FOUR);
    return 0;
}

/*
result:

test1:
Case 1 detected
Case 4 detected

option = 00001001
CASE_ONE = 00000001
option & CASE_ONE = 00000001
CASE_FOUR = 00001000
option & CASE_FOUR = 00001000

test2:
Case 1 detected
Case 2 detected

option = 00000011
CASE_ONE = 00000001
option & CASE_ONE = 00000001
CASE_TWO = 00000010
option & CASE_TWO = 00000010

test3:
Case 1 detected
Case 2 detected
Case 3 detected
Case 4 detected

option = 00001111
CASE_ONE = 00000001
option & CASE_ONE = 00000001
CASE_TWO = 00000010
option & CASE_TWO = 00000010
CASE_THREE = 00000100
option & CASE_THREE = 00000100
CASE_FOUR = 00001000
option & CASE_FOUR = 00001000
*/