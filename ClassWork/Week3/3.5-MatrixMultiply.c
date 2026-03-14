#include <stdio.h>

void zeroMatrix(int row, int col, int matrix[row][col]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            matrix[i][j] = 0;
        }
    }
}

void scanMatrix(int row, int col, int matrix[row][col]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int row, int col, int matrix[row][col]){
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int row, int roco, int col, 
            int a[row][roco], 
            int b[roco][col], 
            int product[row][col])
{
    
    for (int r = 0 ; r < row; r++){
        for (int c = 0; c < col; c++){
            for (int n = 0; n < roco; n++){
                product[r][c] += a[r][n] * b[n][c];
            }
        }
    }
}   

int main(){
    int row, roco, col;
    printf("Enter n, m, l:");
    scanf("%d %d %d", &row, &roco, &col);

    int matrixA[row][roco];
    int matrixB[roco][col];
    int product[row][col];

    scanMatrix(row, roco, matrixA);
    scanMatrix(roco, col, matrixB);

    zeroMatrix(row, col, product);
    
    multiplyMatrices(row, roco, col, matrixA, matrixB, product);

    printMatrix(row, col, product);


    return 0; 
}