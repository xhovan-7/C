#include <stdio.h>
#include "func.h"


int main(){
    //open File
    FILE *fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL){puts("File failed to open!");   return 1;}

    //get the number of students by counting nr of lines in file
    int size = getSize(fp);


    //create stuct Student
    Student students[size];
    
    //get the data from the file
    readStudents(fp, students, size);

    fclose(fp);

    sortAvgAscending(students, size);



    return 0;
}