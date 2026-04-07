#ifndef FUNC_H
#define FUNC_H

void getSize(FILE *fp, int *row, int *col);

void scanMatrix(FILE *fp,int row, int col, int matrix[row][col]);

void sortMatrix(int row, int col, int matrix[row][col]);


void printMatrix(int row, int col, int matrix[row][col]);


#endif