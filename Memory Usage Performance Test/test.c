#include <stdio.h>
#include <stdlib.h>
#define ROW 5
#define COL 5

int main(){

    //first method
    int matrix1[ROW][COL];

    printf("matrix1 address:\n");
    for (int i = 0; i < ROW;i++){
        for (int j = 0; j < COL;j++){
            printf("%u  ", &matrix1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //second method
    int **matrix2 = malloc(sizeof(int *)*ROW);
    for (int i = 0; i < ROW;i++){
        matrix2[i] = malloc(sizeof(int) * COL);
    }

    
    printf("matrix2 address:\n");
    for (int i = 0; i < ROW;i++){
        for (int j = 0; j < COL;j++){
            printf("%u  ", &matrix2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}