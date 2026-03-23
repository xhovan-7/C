
#include <stdio.h>
#include <string.h>


typedef struct Student{
    double grade1, grade2;
    char name[20];
    char surname[20];
}Student;
/*
Student createStudent(int grade1, int grade2, char name[20], char surname[20]){
    Student s; 
    s.grade1 = grade1;
    s.grade2 = grade2;
    strcpy (s.name, name);
    strcpy (s.surname, surname);
    return s;
}
*/


int main(){

    FILE *studFiles;
    studFiles = fopen("data.txt", "r");
    if (studFiles == NULL){
        printf("File doesn't exist!");
        return 1;
    }

    FILE *sucFile;
    sucFile = fopen("sucFile.txt", "a");
    if (sucFile == NULL){
        printf("SucFile can't be created!");
        return 1;
    }

    FILE *failFile;
    failFile = fopen("failFile.txt", "a");
    if (failFile == NULL){
        printf("FailFile can't be created!");
        return 1;
    }

    int count = 0;
    int failCnt = 0;
    int sucCnt = 0;

    Student stud[100];
    while (fscanf(studFiles, "%19s %19s %lf %lf", 
                    stud[count].name,
                    stud[count].surname,
                    &stud[count].grade1,
                    &stud[count].grade2) == 4){
        count++;
    }

    fclose(studFiles);

    for (int i = 0; i < count; i++){
        double avg = (stud[i].grade1 + stud[i].grade2) / 2;
        if (avg < 5){
            fprintf(failFile, "%s %s %.2lf %.2lf\n", stud[i].name, stud[i].surname, stud[i].grade1, stud[i].grade2);
            failCnt++;
        }
        else{
            fprintf(sucFile, "%s %s %.2lf %.2lf\n", stud[i].name, stud[i].surname, stud[i].grade1, stud[i].grade2);
            sucCnt++;
        }
    }

    printf("sucFile.txt has %d students. \nfailFile.txt has %d students.", sucCnt, failCnt);

    fclose(sucFile);
    fclose(failFile);


    return 0;
}