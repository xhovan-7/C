#include "func.h"



int getSize(){
    int size;
    printf("Enter number of students: ");
    scanf("%d", &size);
    
    return size;
}

void readSubject(Subject subjects[], int size){
    
    for (int i = 0; i < size; i++){
        printf("Enter the name of subject %d: ", i + 1);
        scanf("%24s", subjects[i].name);

        printf("Enter ETCS for %s: ", subjects[i].name);
        scanf("%d", &subjects[i].ects);
    }
    puts("");
}


void readData(Student students[], int size, Subject subjects[2]){
    for (int i = 0; i < size; i++){
        printf("Enter details for student %d:\nName: ", i + 1);
        scanf("%24s", students[i].persons.name);

        printf("Surname: ");
        scanf("%24s", students[i].persons.surname);

        printf("Age: ");
        scanf("%d", &students[i].persons.age);

        for (int j = 0; j < 2; j++){
            printf("Enter grade for %s: ", subjects[j].name);
            scanf("%d", &students[i].grades[j]);
        }

        students[i].avg = getAvg(students[i], subjects);

        puts("");
    }
}

double getAvg(Student s, Subject subjects[2]){
    int sum = 0;
    int ects = 0;

    for (int i = 0; i < 2; i++){
        sum += s.grades[i] * subjects[i].ects;
        ects += subjects[i].ects;
    }

    return (float)sum / (float)ects;
}


void printStudents(Student students[], int size, Subject subjects[2]){
    printf("Data for each student:\n");

    for (int i = 0; i < size; i++){
        printf("Name: %s\nSurname: %s\nAge: %d\nAverage grade: %.2lf\n%s: %d, %s: %d\n\n",
                            students[i].persons.name, 
                            students[i].persons.surname,
                            students[i].persons.age,
                            students[i].avg,
                            subjects[0].name,
                            students[i].grades[0],
                            subjects[1].name,
                            students[i].grades[1]);
    }
}


void printMax(Student students[], int size){
    int max = 0;
    for (int i = 1; i < size; i++){
        if(students[max].avg < students[i].avg) max = i;
    }

    printf("The student with the highest average is:\n%s %s - %.2lf", 
            students[max].persons.name, 
            students[max].persons.surname, 
            students[max].avg);

}
