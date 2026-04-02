#include <stdio.h>
#include "func.h"

int getSize(){
    int size;

    printf("Enter the number of students: ");
    scanf("%d", &size);

    while(size <= 0 && size >100){
        printf("Enter a number between 1 - 100: ");
        scanf("%d", &size);
    }

    return size;
}


typedef struct Student
{
    char name[16];
    double avg;
    int grades[100];
}Student;

Student *getGrades(int size){

    Student *student = malloc(size * sizeof(Student));
    if (student == NULL) return NULL;

    for (int i = 0; i < size; i++){
        printf("%d: ", i);
        scanf("%s", student[i].name);

        int j = 0;
        while(1){
            scanf("%d", &student[i].grades[j]);

            if (student[i].grades[j++] == -999)   break;
        }

        int sum = 0;
        for (int k = 0; k < j; k++){
            sum += student[i].grades[k];
        }

        student[i].avg = (float)sum / (float)j;

    }



}


