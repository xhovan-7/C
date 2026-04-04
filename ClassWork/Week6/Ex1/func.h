#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char name[16];
    double avg;
    int grades[100];
}Student;

int getSize(FILE *source);

/*
double getTarget();
*/

Student *readStudents(FILE *source, int size);

void sortByAvg(Student *students, int size);

void printStudent(Student *students, int size);

double getTarget();

int binarySearch(Student *students, int size, double target);

void printTarget(Student *students, int size, int index, double target);

#endif 