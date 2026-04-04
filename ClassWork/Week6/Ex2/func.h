#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Donor{
    int donatedMoney;
    char name[25];
}Donor;

void getSize(FILE *source, int *nrDonors, int *topDonors);

Donor *readDonor(FILE *source, int *nrDonors, int *topDonors);


#endif