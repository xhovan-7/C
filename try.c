#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    char surname[50];
    double grade;
} Student;

Student *readStudents(FILE *fp, int *count) {
    int capacity = 2;
    *count = 0;

    Student *students = malloc(capacity * sizeof(Student));
    if (students == NULL) return NULL;

    while (fscanf(fp, "%d %49s %49s %lf",
                  &students[*count].id,
                  students[*count].name,
                  students[*count].surname,
                  &students[*count].grade) == 4) {

        (*count)++;

        if (*count == capacity) {
            capacity *= 2;
            Student *temp = realloc(students, capacity * sizeof(Student));
            if (temp == NULL) {
                free(students);
                return NULL;
            }
            students = temp;
        }
    }

    return students;
}

int main() {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("File could not be opened\n");
        return 1;
    }

    int count;
    Student *students = readStudents(fp, &count);
    fclose(fp);

    if (students == NULL) {
        printf("Error reading students\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("%d %s %s %.2lf\n",
               students[i].id,
               students[i].name,
               students[i].surname,
               students[i].grade);
    }

    free(students);
    return 0;
}