#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void getSiPo(FILE *fp, int *size, int *position){
    int si;
    int pos;
    char line[101];
    fgets(line, 100, fp);
    sscanf(line, "%d %d", &si, &pos);
    
    *size = si;
    *position = pos;
    
}

int getSize(FILE *fp){
    char line[101];
    int size;
    fgets(line, 100, fp);

    sscanf(line, "%ld", &size);
    return size;
}

Person *readPerson(FILE *fp, int size){
    Person *persons = malloc(size * sizeof(Person));
    if (persons == NULL){
        printf("Mallocation failed!\n");
        exit(1);
    }

    char line[101];
    char name[12];
    char surname[12];

    for (int i = 0; i < size; i++){
        fgets(line , 100, fp);
        sscanf(line, "%12s %12s %10ld", name, surname, &persons[i].pin);
        sprintf(persons[i].name, "%s %s", name, surname);
    }
    return persons;
}

Person *mergeStruct(Person *persons1, Person *persons2, int size1, int size2){
    Person *personTotal = malloc((size1 + size2) * sizeof(Person));
    if (personTotal == NULL){
        printf("Mallocation Failed - personTotal\n");
        exit (1);
    }

    int i = 0;
    for (int j = 0; j < size1; j++){
        personTotal[i++] = persons1[j];
    }

    for (int j = 0; j < size2; j++){
        personTotal[i++] = persons2[j];
    }

    return personTotal;
}

void sortAscending(Person *persons, int size){
    Person temp; 

    for (int i = 0; i < size - 1; i++){
        int min = i;

        for (int j = i + 1; j < size;j++){
            if (persons[min].pin > persons[j].pin){
                min = j;
            }
        }

        temp = persons[i];
        persons[i] = persons[min];
        persons[min] = temp;
    }
}


void printTarget(Person *persons, int target){
    printf("%s %ld", persons[target].name, persons[target].pin);
}


void printPersons(Person *persons, int size){
    for (int i = 0; i < size; i++){
        printf("%d: %s - %ld\n", i + 1, persons[i].name, persons[i].pin);
    }
}