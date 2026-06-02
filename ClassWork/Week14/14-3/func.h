#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char name[25];
    char surname[25];
    char dep[5];
    float gpa1, gpa2, gpa3;
    float cgpa;
    int status;

    struct Student *next;
}Student;
