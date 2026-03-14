#include <stdio.h>
#include<stdbool.h>

void scanMatrix(int row, int col, double matrix[row][col]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            scanf("%lf", &matrix[i][j]);
        }
    }
}

bool isMarkovMatrix(int size, double matrix[size][size]){
    for (int i = 0; i < size; i++){
        int sum = 0;
        for (int j = 0; j < size; j++){
            if (matrix[j][i] <= 0)  return false;
            sum += matrix[j][i];
        }
        if (sum != 1) return false;
    }

    return true;
}

int main(){
    int size;
    double matrix[size][size];

    printf("Enter size:");
    scanf("%d", &size);
    
    scanMatrix(size, size, matrix);

    printf("It is");

    if (!isMarkovMatrix(size, matrix))
        printf("n't");
    
    printf(" a Markov matrix");



    return 0;
}