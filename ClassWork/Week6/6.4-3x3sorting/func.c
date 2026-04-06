#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void getSize(FILE *fp,int *row, int *col){
    char line[101];

    fgets(line, 100, fp);
    sscanf(line, "%d %d", row, col);

}

void scanMatrix(FILE *fp, int **matrix, int row, int col){
    *matrix = malloc(row * col * sizeof(int));
    if (*matrix == NULL){
        puts("Malloc Failed!");
        exit (1);
    }

    int *p_matrix = *matrix;

    for (int i = 0; i < row; i++){

        char line[101];
        fgets(line, 100, fp);
        char *ptr = line;
        int offset = 0;
        for (int j = 0; j < col;j++){
            sscanf(ptr, "%d%n", &p_matrix[i * col + j], &offset);
            printf("%d", p_matrix[i * col + j]);
            ptr += offset;
        }
        puts("");
    }
}

void printMatrix(int **matrix, int row, int col){
    int *p_matrix = *matrix;
    printf("%d by %d Matrix:", row, col);
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%4d", p_matrix[i * col + j]);
        }
        puts("");
    }
}


void sortmatrix(int **matrix, int row, int col){
    int min = 0;

    for (int i = 0; i < row * col; i++){
        for (int j = 0; j < row; j++){
            for (int k = j +1 )
        }
    }
}

