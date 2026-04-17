#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Grade{
    int grade;
}Grade;


typedef struct Student{
    int id;
    char name[20];
    char surname[20];
    Grade *grades;
}Student;

void getSize(FILE *fp, int *std, int *grdSize);

Student *createStudent(int size, int gradeSize);

void getData(FILE *fp, Student *students);

void printStudents(Student *students, int size, int gradeSize);

void free_students(Student *students);
#endif