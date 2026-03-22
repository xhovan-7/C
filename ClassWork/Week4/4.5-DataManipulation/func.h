#ifndef STUDENT_FUNC_H
#define STUDENT_FUNC_H

void readData(FILE *infile, int id[], 
            char name[][20], char surname[][20], 
            char dep[][20], double grade[], int n);


void printData(FILE *outfile, int id[], 
            char name[][20], char surname[][20], 
            char dep[][20], double grade[], int n);


void printStudentInfo(FILE *outfile, int id[], 
                    char name[][20], char surname[][20], 
                    char dep[][20], double grade[], 
                    int n, char searchName[20], 
                    char searchSurname[20]);


void printDep(FILE *outfile, int id[], 
            char name[][20], char surname[][20], 
            char dep[][20], double grade[], 
            int n, char depName[20], int minGrade);

            
#endif