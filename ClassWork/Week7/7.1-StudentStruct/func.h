#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char name[16];
    char surname[16];
    int grades[4];
    double avg;
}Student;

int getSize(FILE *fp);

Student *createStudent(int size);

void readStudents(FILE *fp, Student students[], int size);

double getAvg(Student students);

void sortAvgAscending(Student students[], int size);

void printStudents(Student students[], int size);
#endif