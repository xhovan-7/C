#include <stdio.h>
#include "func.h"
FILE *infile;
FILE *copy;


int main(){
    
    infile = fopen("data.txt", "r");
    
    if (infile == NULL){
    printf("File couldn't be  opened!\n");
    exit(1);
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
    


    readData(infile, id, name, surname, 
    dep, grade, lines);

    fclose(infile);
    
    copy = fopen("data-copy.exe", "w+");

    if (copy == NULL){
        printf("File couldn't be created!");
        exit(1);
    }

    printData(copy, id, name, surname, dep, grade, lines);

    printStudentInfo(copy, lines);


    return 0;
}
