#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define ROWS 100000
#define COLS 10000

int matrix[ROWS][COLS];

int main(){

    int i, j;

    for (i = 0; i < ROWS;i++){
        for (j = 0; j < COLS;j++){
            matrix[i][j] = rand();
        }
    }

    //get the sum of all elements in matrix
    int64_t sum = 0;
    for (i = 0; i < ROWS;i++){
        for (j = 0; j < COLS;j++){
            sum+= matrix[i][j];
        }
    }
    printf("sum = %ld\n", sum);
    return 0;
}