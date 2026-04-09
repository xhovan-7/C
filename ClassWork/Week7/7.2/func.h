#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    int grades[6];
    double avg;
    char name[16];
    char surname[16];
}Student;

int getSize(FILE *fp);

double getAvg(Student students);

void readData(FILE *fp, Student students[], int size);

void printMax(Student students[], int size);

void printStudents(Student students[], int size);

#endif