#ifndef STUDENT_FUNC_H
#define STUDENT_FUNC_H
#include <stdio.h>

void readData(FILE *infile, int id[], char name[][20],
            char surname[][20], char dep[][20], 
            double grade[], int lines);


void printData(FILE *copy, int id[], char name[][20], 
            char surname[][20], char dep[][20], 
            double grade[], int lines);


void printStudentInfo(FILE *copy, int lines);


void printDep(FILE *depFile, int id[], 
            char name[][20], char surname[][20], 
            char dep[][20], double grade[], 
            int lines, char depName[20], int minGrade);

            
#endif