#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>


void getSize(FILE *fp, int *row, int *col);

void scanMatrix(FILE *fp, int **matrix, int row, int col);

void printMatrix(int **matrix, int row, int col);

void sortmatrix(int **matrix, int row, int col);
#endif