#include <stdio.h>
const int SIZE = 4;

void scanMatrix(double matrix[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            scanf("%lf", &matrix[i][j]);
        }
    }
}

double sumMajorDiagonal(double matrix[SIZE][SIZE]){
    double sum = 0;
    for(int i = 0; i < SIZE; i++){
        sum += matrix[i][i];
    }
    return sum;
}

double sumMinorDiagonal(double matrix[SIZE][SIZE]){
    double sum = 0;
    for(int i = 0; i < SIZE; i++){
        sum += matrix[i][SIZE - 1 - i];
    }
    return sum;
}



int main(){
    double matrix[SIZE][SIZE];

    printf("Enter a 4-by-4 matrix row by row: \n");
    scanMatrix(matrix);

    double sumMajor = sumMajorDiagonal(matrix);
    double sumMinor = sumMinorDiagonal(matrix);

    printf("Sum of the elements in the major diagonal is %.2lf\n", sumMajor);
    printf("Sum of the elements in the minor diagonal is %.2lf", sumMinor);


    return 0;
}