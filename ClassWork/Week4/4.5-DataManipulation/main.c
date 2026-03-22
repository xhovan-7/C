#include <stdio.h>
#include "func.h"
FILE *infile;
FILE *copy;
FILE *depFile;


int main(){
  
    infile = fopen("data.txt", "r");
    
    if (infile == NULL){
    printf("File couldn't be  opened!\n");
    return 1;
    }

    int lines;
    fscanf(infile, "%d", &lines);
    
    int id[lines];
    double grade[lines];
    char name[lines][20];
    char surname[lines][20];
    char dep[lines][20];
    char searchName[20];
    char searchSurname[20];
    char depName[20];
    int minGrade;
    char fileName[20];
    


    readData(infile, id, name, surname, 
    dep, grade, lines);

    fclose(infile);
    
    copy = fopen("data-copy.exe", "w+");
    if (copy == NULL){
        printf("File couldn't be created!");
        return 1;
    }

    printData(copy, id, name, surname, dep, grade, lines);

    printStudentInfo(copy, lines);

    fclose(copy);

    printf("Enter the department and the minimum grade: ");
    scanf("%s %d", depName, &minGrade);
    sprintf(fileName, "%s  >%d.txt", depName, minGrade);

    depFile = fopen(fileName, "w");

    printDep(depFile, id, name, surname, dep, grade, lines, depName, minGrade);


    return 0;
}
