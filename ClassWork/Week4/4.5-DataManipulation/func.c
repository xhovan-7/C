#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"


void readData(FILE *infile, int id[], char name[][20],
    char surname[][20], char dep[][20], 
    double grade[], int lines){
    int i = 0;

    while (i < lines && (infile,"%5d %19s %19s %19s %fl", &id[i], name[i], surname[i], dep[i], &grade[i]) == 5){
        i++;        
    }

    
    fclose(infile);
}

void printData(FILE *copy, int id[], char name[][20], char surname[][20], char dep[][20], double grade[], int lines){

    for (int i = 0; i < lines; i++){
        sprintf("%d %s %s %s %lf\n", id[i], name[i], surname[i], dep[i], grade[i]);
    }

    rewind(copy);
}

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

    while (i < lines && (fscanf("%d %s %s %s %lf", &id, name, surname, dep, &grade) == 5)){
        if (strcmp(name, searchName) || strcmp(surname, searchSurname) == 0){
            fprintf(copy, "%d %s %s %s %lf\n", id, name, surname, dep, grade);
            return;
        }
    }

}

void printDep(FILE *outfile, int id[], char name[][20], char surname[][20], char dep[][20], double grade[], int n, char depName[20], int minGrade){

}