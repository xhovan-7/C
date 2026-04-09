#include <stdio.h>
#include "func.h"


void getSize(FILE *fp, int *row, int *col){
    char line[101]; 
    fgets(line, 100, fp);
    sscanf(line, "%d %d", row, col);
}


void scanMatrix(FILE *fp,int row, int col, int matrix[row][col]){
    char line[101];

    for (int i = 0; i < row; i++){
        fgets(line, 100, fp);
        char *ptr = line;
        int offset = 0;
        for (int j = 0; j < col; j++){
            sscanf(ptr, "%d%n", &matrix[i][j], &offset);
            printf("%d ", matrix[i][j]);
            ptr += offset;
        }
        puts("");
    }
}


void sortMatrix(int row, int col, int matrix[row][col]){
    for (int i = 0; i < row * col - 1; i++){
        int minR = i / col;
        int minC = i % col;
        for (int j = i / col; j < row; j++){ // nqs i=4, eshte rreshti 2, colona 1; pra j = 1, k = 1;
            for (int k = i % col; k < col; k++){
                if (matrix[minR][minC] > matrix[j][k]){
                    minR = j;
                    minR = k;
                }
            }
            int temp = matrix[minR][minC];
            matrix[minR][minC] = matrix[i / col][i % col];
            matrix[i / col][i % col] = temp;
        }
    }
}

void printMatrix(int row, int col, int matrix[row][col]){
    printf("Matrix%dx%d sorted is:\n", row, col);

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("[%d][%d]: %d\t", i, j, matrix[i][j]);
        }
        puts("");
    }
}