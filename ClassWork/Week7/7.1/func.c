#include <stdio.h>
#include "func.h"

int getSize(FILE *fp){
    char line[100];
    int count = 0;
    
    while (fgets(line, 100, fp) != NULL){
    count++;
    }
    if (count == 0){
        puts("Empty File!");
        exit(1);
    }
    rewind(fp);

    printf("Nr students: %d\n", count);
    
    return count;
}

/*
Student *createStudent(int size){
    Student *students = malloc(size * sizeof(Student));
    if (students == NULL){
        puts("Malloc failed!");
        return NULL;
    }
    return students;
}

*/


void readStudents(FILE *fp, Student students[], int size){
    for (int i = 0; i < size; i++){
        char line[100];
        fgets(line, 100, fp);

        sscanf(line, "%15s %15s %d %d %d %d", 
                    students[i].name,
                    students[i].surname,
                    &students[i].grades[0],
                    &students[i].grades[1],
                    &students[i].grades[2],
                    &students[i].grades[3]);

        students[i].avg = getAvg(students[i]);

    }
    puts("Scaned Students:");
    printStudents(students, size);
}


double getAvg(Student students){
    int sum = 0;    
    for (int j = 0; j < 4; j++){
        sum += students.grades[j]; 
    }
    return sum / 4.0;
}


void sortAvgAscending(Student students[], int size){

    for (int i = 0 ; i < size - 1; i++){
        int min = i;
        for (int j = i +  1; j < size; j++){
            if (students[min].avg > students[j].avg){
                min = j;
            }
        }

        Student temp = students[min];
        students[min] = students[i];
        students[i] = temp;
    }
    puts("Students sorted ascending:");
    printStudents(students, size);

}


void printStudents(Student students[], int size){
    for (int i = 0; i < size; i++){
        printf("%d:%s, %s - %.2lf - %d %d %d %d\n",
            i + 1, 
            students[i].name,
            students[i].surname,
            students[i].avg,
            students[i].grades[0],
            students[i].grades[1],
            students[i].grades[2],
            students[i].grades[3]);
    }
}