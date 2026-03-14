#include <stdio.h>

void scanMatrix(int row, int col, double matrix[row][col]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void addMatrix(int row, int col, 
            double a[row][col], 
            double b[row][col], 
            double sum[row][col]){
    for (int i = 0 ; i < row; i++){
        for (int j = 0; j < col; j++){
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}   

void printMatrix(int row, int col, double matrix[row][col]){
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%.1lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){

    int row, col;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &col);

    double matrix1[row][col];
    double matrix2[row][col];
    double sum[row][col];

    printf("Enter elements of first matrix:");
    scanMatrix(row, col, matrix1);
    printf("Enter elements of second matrix:");
    scanMatrix(row, col, matrix2);

    addMatrix(row, col, matrix1, matrix2, sum);

    printf("Sum of matrices:\n");
    printMatrix(row, col, sum);

    return 0; 
}