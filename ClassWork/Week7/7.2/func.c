#include "func.h"


int getSize(FILE *fp){
    int count = 0;
    char line[100];

    while(fgets(line, 100, fp) != NULL){
        count++;
    }
    rewind(fp);

    printf("Nr of students: %d\n", count);

    return count;
}


double getAvg(Student students){
    int sum = 0;
    int i = 0;
    while(students.grades[i] != -1){
        sum += students.grades[i];
        if (i++ == 5) break;
    }

    if (i < 4) i = 4;

    return (double)sum / (double)i; 
}

void readData(FILE *fp, Student students[], int size){
    char line[100];
    int i = 0;
    while (fgets(line, 100, fp) != NULL){
        char *ptr = line;
        int offset = 0;

        sscanf(ptr, "%15s %15s%n", students[i].name, students[i].surname, &offset);
        ptr += offset;
        
        for(int j = 0; j < 6; j++){
            sscanf(ptr, "%d%n", &students[i].grades[j], &offset);
            ptr += offset;
        }

        students[i].avg = getAvg(students[i]);

        i++;
    }
    
}

void printMax(Student students[], int size){
    int max = 0;
    for (int i = 1; i < size; i++){
        if (students[max].avg < students[i].avg) max = i;
    }

    printf("%s %s %.2lf\n", students[max].name, students[max].surname, students[max].avg);

}

void printStudents(Student students[], int size){
    for (int i = 0; i < size; i++){
        printf("%d:%s, %s - %.2lf - ",
            i + 1, 
            students[i].name,
            students[i].surname,
            students[i].avg);
        for (int j = 0; j < 6 && students[i].grades[j] != -1; j++){
            printf("%d ", students[i].grades[j]);
        }
        puts("");
    }
}