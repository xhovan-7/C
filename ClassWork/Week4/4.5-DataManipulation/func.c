#include <stdio.h>
#include <string.h>
#include "func.h"

//store data from the file into 2D arrays in memorey
void readData(FILE *infile, int id[], char name[][20],
    char surname[][20], char dep[][20], 
    double grade[], int lines){
    int i = 0;

    while (i < lines && (fscanf(infile,"%d %19s %19s %19s %lf", &id[i], name[i], surname[i], dep[i], &grade[i])) == 5){
        i++;        
    }
}

//print data into a new file 
void printData(FILE *copy, int id[], char name[][20], 
    char surname[][20], char dep[][20], 
    double grade[], int lines){

    for (int i = 0; i < lines; i++){
        fprintf(copy, "%d %s %s %s %.2lf\n", id[i], name[i], surname[i], dep[i], grade[i]);
    }

    
}

//print info of a student into terminal
void printStudentInfo(FILE *copy, int lines){
    int i = 0;
    int id;
    double grade;
    char name[20];
    char surname[20];
    char dep[20];
    char searchName[20];
    char searchSurname[20];

    printf("Enter Student Name and Surname:");
    scanf("%19s %19s", searchName, searchSurname);

    rewind(copy);

    while (i < lines && (fscanf(copy, "%d %19s %19s %19s %lf", &id, name, surname, dep, &grade) == 5)){
        if ((strcmp(name, searchName) == 0) && (strcmp(surname, searchSurname) == 0)){
            printf("%d %s %s %s %.2lf\n", id, name, surname, dep, grade);
            return;
        }
        i++;
    }
    
    printf("No Student found!\n");

}

//print all students with 'grade' > 'minGrade' from XXX department 
void printDep(FILE *depFile, int id[], char name[][20], 
    char surname[][20], char dep[][20], 
    double grade[], int lines,
    char depName[20], int minGrade){

    for (int i = 0; i < lines; i++){
        if ((strcmp(dep[i], depName) == 0) && (grade[i] > (float)minGrade)){
            fprintf(depFile, "%d %s %s %s %.2lf\n", id[i], name[i], surname[i], dep[i], grade[i]);
        }
    }

}