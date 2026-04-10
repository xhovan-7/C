#ifndef FUNC_H
#define FUNC_H 
#include <stdio.h>

typedef struct Donor{
    char name[12];
    char surname[12];
    double amountDonated;
}Donor;

int getSize(FILE *fp);

void readData(FILE *fp, Donor donors[], int size);

Donor findMax(Donor donors[], int size);

Donor findSecond(Donor donors[], int size);

void printDonor(Donor d);

#endif