//#include <stdio.h>
#include "func.h"


int main(){

    FILE *fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL){puts("File failed to open!"); return 1;}

    int size = getSize(fp);
    if (size == 0) {puts("Empty File!"); return 1; }

    Student students[size];

    readData(fp, students, size);

    printMax(students, size);

    printStudents(students, size);

    fclose(fp);

    return 0;
}