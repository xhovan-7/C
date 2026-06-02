#pragma once

typedef struct Student{
    char name[16];
    char surname[16];
    int grades[6];
    double avg;

    struct Student *next;
}Student;


void *readList(Student **head, Student *temp){
    Student *newNode;



}