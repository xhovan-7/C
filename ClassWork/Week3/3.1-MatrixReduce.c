#include <stdio.h>

void scanList(int list[], int size){
    for (int i = 0; i < size; i++){
        scanf("%d", &list[i]);
    }
}

void matrixReduce(int row, int col, int matrix[row][col]){
    for (int i = 0; i < row; i++){
        int min = matrix[i][0];
        for (int j = 1; j < col;j++){
            if (min > matrix[i][j])
                min = matrix[i][j];
        }

        for (int j = 0; j < col; j++){
            matrix[i][j] -= min;
        }
    }

}

void printList(int list[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", list[i]);
    }
}


int main() {
    int row;
    int col;
    int matrix[3][6];
    
    printf("Enter nr of rows and columns: ");
    scanf("%d %d", &row, &col);

    for (int i = 0; i < row; i++){
        scanList(matrix[i],col);
    }

    matrixReduce(row, col, matrix);

    for (int i = 0; i < row; i++){
        printList(matrix[i], col);
        printf("\n");
    }
    
    
    
    return 0;
}