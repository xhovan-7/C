#ifndef FUNC_H
#define FUNC_H
#include <stdlib.h>

typedef struct Person{
    long pin;
    char name[26];
}Person;

void getSiPo(FILE *fp, int *size, int *position);

int getSize(FILE *fp);

Person *readPerson(FILE *fp, int size);

Person *mergeStruct(Person *persons1, Person *person2, int size1, int size2);

void sortAscending(Person *persons, int size);

void printTarget(Person *persons, int target);

void printPersons(Person *persons, int size);

#endif