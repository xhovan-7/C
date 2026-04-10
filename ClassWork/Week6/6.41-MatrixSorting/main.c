#include <stdio.h>
#include <stdlib.h>
#include "func.h"



int main(){
    
    FILE *fp;
    fp = fopen("data.txt", "r");    
    if (fp == NULL){puts("File failed to open!"); exit(1);}

    int row, col;
    getSize(fp, &row, &col);

    int matrix[row][col];

    printf("Matrix: %dx%d\n", row, col);

    scanMatrix(fp, row, col, matrix);
    
    fclose(fp);

    sortMatrix(row, col, matrix);

    printMatrix(row, col, matrix); 


    return 0;
}