#include <string.h>
#include "func.h"




int main(){
    FILE *source;
    source = fopen("data.txt", "r");
    
    if (source == NULL){
        printf("Error opening file \n");
        return 1;
    }
    else {
        printf("File opened successfully");
    }

    int size = getSize(source);

    if (size == -1){
        printf("No student recorded ...");
        return 1;
    }

    Student *students = readStudents(source, size);
    if (students == NULL){
        printf("File failed to mallocate\n");
        return 1;
    }

    fclose(source);

    sortByAvg(students, size);
    printf("Students sorted!");

    printStudent(students, size);
    printf("Students printed");

    double target = getTarget();

    int targetIndex = binarySearch(students, size, target);

    printTarget(students, size, targetIndex, target);


    free(students);
    return 0;
}
