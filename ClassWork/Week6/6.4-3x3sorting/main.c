#include <stdio.h>
#include <stdlib.h>
#include "func.h"


int main(){
    FILE *fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL){
        puts("File couldn't open!");
        return 1;
    }

    int row, col;
    getSize(fp, &row, &col);

    int *matrix = NULL;
    scanMatrix(fp, &matrix, row, col);


    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d", matrix[i * col + j]);
        }
        puts("");
    }


    printMatrix(&matrix, row, col);




    return 0;
}