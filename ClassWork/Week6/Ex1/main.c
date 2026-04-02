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


typedef struct Student{
    char name[16];
    double avg;
    int grades[100];
}Student;

void getNameGrades(Student students[], int size){

    
    for (int i = 0; i < size; i++){
        printf("%d: ", i);
        scanf("%s", students[i].name);

        int j = 0;
        while(1){
            scanf("%d", &students[i].grades[j]);

            if (students[i].grades[j++] == -999)   break;
        }

        int sum = 0;
        for (int k = 0; k < j; k++){
            sum += students[i].grades[k];
        }

        students[i].avg = (float)sum / (float)j;

    }
}




int main(){
    int size;
    size = getSize;

    Student students[100];

    getNameGrades(students, size);



    return 0; 
}