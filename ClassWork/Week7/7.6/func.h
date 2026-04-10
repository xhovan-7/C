#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <string.h>

typedef struct Student{
    char name[24];
    char surname[16];
    int grades[4];
    double avg;
}Student;

int getSize(FILE *fp);

void readData(FILE *fp, Student students[], int size);

void getAvg(Student students[], int size);

void printStudent(Student students[], int size);

#endif