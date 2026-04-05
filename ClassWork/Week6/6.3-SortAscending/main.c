#include <stdio.h>
#include <stdlib.h>
#include "func.h"


int main(){
    FILE *fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL){
        printf("File couldn't open!");
        return 1;
    }

    int size1;
    int target;
    getSiPo(fp, &size1, &target);

    Person *persons1 = readPerson(fp, size1);

    int size2 = getSize(fp);

    Person *persons2 = readPerson(fp, size2);

    Person *personTotal = mergeStruct(persons1, persons2, size1, size2);
    
    free(persons1);
    free(persons2);

    int sizeTotal = size1 + size2;
    sortAscending(personTotal, sizeTotal);

    printPersons(personTotal, sizeTotal);

    printTarget(personTotal, target - 1);


    return 0;
}