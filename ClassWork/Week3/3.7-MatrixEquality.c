#include <stdio.h>
#include <stdbool.h>

void scanMatrix(int row, int col, int matrix[row][col]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

bool equalMatrix (int row, int col, int A[row][col], int B[row][col]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (A[i][j] != B[i][j]) return false;
        }
    }
    return true;
}

int main(){
    int row, col;

    printf("Enter size:");
    scanf("%d %d", &row, &col);

    int matrixA[row][col];
    int matrixB[row][col];

    printf("Enter first Matrix:");
    scanMatrix(row, col, matrixA);
    printf("Enter second Matrix:");
    scanMatrix(row, col, matrixB);

    printf("The two Matrices are %s", equalMatrix(row, col, matrixA, matrixB) ? "striclty identical"
                                                                              : "NOT identical.");

    return 0;
}