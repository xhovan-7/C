#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Donor{
    float donatedMoney;
    char name[13];
    char surname[13];
}Donor;

void getSize(FILE *source, int *nrDonors, int *topDonors);

Donor *readDonor(FILE *source, int size);

void sortDescending(Donor *donors, int size);

void printDonors(Donor *donors, int size);

#endif