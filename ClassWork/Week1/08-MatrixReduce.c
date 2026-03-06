#include <stdio.h>

void scanList(int list[], int size){
    for (int i = 0; i < size; i++){
        scanf("%d", &list[i]);
    }
}

void printList(int list[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", list[i]);
    }
}


int main() {
    int row;
    int column;
    int matrix[3][6];
    
    printf("Enter nr of rows and columns: ");
    scanf("%d %d", &row, &column);

    for (int i = 0; i < row; i++){
        scanList(matrix[i],column);
    }

    for (int i = 0; i < row; i++){
        int min = matrix[i][0];
        for (int j = 1; j < column;j++){
            if (min > matrix[i][j])
                min = matrix[i][j];
        }

        for (int j = 0; j < column; j++){
            matrix[i][j] -= min;
        }
    }

    for (int i = 0; i < row; i++){
        printList(matrix[i], column);
        printf("\n");
    }
    
    
    
    return 0;
}