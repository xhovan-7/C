#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Person{
    char name[25]; 
    char surname[20]; 
    int age;
}Person;

typedef struct Student{ 
    Person persons;
    int grades[2];
    double avg;
}Student;

typedef struct Subject{
    char name[25]; 
    int ects; 
}Subject;

int getSize();

void readSubject(Subject subjects[], int size2);

void readData(Student students[], int size, Subject subjects[2]);

double getAvg(Student s, Subject subjects[2]);

void printStudents(Student students[], int size, Subject subjects[2]);

void printMax(Student students[], int size);

#endif