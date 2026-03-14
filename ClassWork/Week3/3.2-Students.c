#include <stdio.h>

void scanMatrix(int row, int col, int matrix[row][col]){
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

int minMatrix(int row, int col, int matrix[row][col]){
    int min = matrix[0][0];
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if ((min > matrix[i][j]))
                min = matrix[i][j];            
        }
    }
    return min;
}

int maxMatrix(int row, int col, int matrix[row][col], int *p_row, int *p_col){
    int max = matrix[0][0];
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if ((max < matrix[i][j])){
                max = matrix[i][j]; 
                *p_row = i;
                *p_col = j;           
            }
        }
    }
    
    return max;
}

double avgStudent (int col, int matrix[]){
    double sum = 0;
    for (int i = 0; i < col; i++){
        sum += matrix[i];
    }
    return sum / col;
}


int main(){

    int stdGrades[10][10];
    int row; 
    int col;
    int min;
    int max;
    int rowMax, colMax;
    int *p_rowMax = &rowMax;
    int *p_colMax = &colMax;
    int index;
    double avg;
    
    printf("Enter nr of students & grades: ");
    scanf("%d %d", &row, &col);

    scanMatrix(row, col, stdGrades);

    printf("Enter index: ");
    scanf("%d", &index);

    min = minMatrix(row, col, stdGrades);
    printf("Lowest grade: %d\n", min);

    
    max = maxMatrix(row, col, stdGrades, p_rowMax, p_colMax);
    printf("Highest grade: %d with index [%d][%d]\n", max, rowMax, colMax);

    avg = avgStudent(col, stdGrades[index]);
    printf("The average grade for student %d is %.2lf\n", index, avg);

    
    return 0; 
}