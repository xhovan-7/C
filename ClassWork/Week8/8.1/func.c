#include "func.h"


void getSize(FILE *fp, int *stdSize, int *gradeSize){
    char line[100];
    int size = 1;
    int grdSize = 0;
    int temp; 
    int offset = 0;
    int grade;
    char temp1[20], temp2[20];
    
    fgets(line, 100, fp);
    char *ptr = line;
    
    sscanf(ptr, "%d %19s %19s%n", &temp, temp1, temp2, &offset);
    *ptr += offset;

    while ((sscanf(ptr, "%d%n", &grade, &offset) == 2)){
        *ptr += offset;
        grdSize++; 
    }
    

    while(fgets(line, 100, fp) != NULL){
        size++;
    }

    *stdSize = size;
    *gradeSize = grdSize;
    rewind(fp);
}



Student *createStudent(int size, int gradeSize){
    Student *students = malloc(sizeof(Student) * size);
    if (students == NULL){  puts("Malloc Failed");  exit(1);}

    students->grades = malloc(sizeof(Grade) * gradeSize);
    if (students->grades == NULL){    puts("Malloc Failed");  exit(1);}
}


void getData(FILE *fp, Student *students){
    char line[100];

    while(fgets(line, 100, fp)){
        char *ptr = line;
        int offset;
        sscanf(ptr, "%d %19s %19s%n", &students->id, students->name, students->surname, &offset);
        ptr += offset;
        int i = 0;

        while (*ptr =! '\0'){
            sscanf(ptr, "%d%n", &students->grades[i++], &offset);
            ptr += offset;
        }
    }
}

void printStudents(Student *students, int size, int gradeSize){
    for (int i = 0; i < size; i++, puts("")){
        printf("%d: %s %s-", students->id, students->name, students->surname);
        for (int j = 0; j < gradeSize; j++){
            printf("%d ", students->grades[j]);
        }
    }
}

void free_students(Student *students){
    if (students == NULL)   return;
    free(students->grades);
    free(students);
}