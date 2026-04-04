#include <stdio.h>
#include <stdlib.h>
#include "func.h"



void getSize(FILE *source, int *nrDonors, int *topDonors){
    char line[100];
    int nrDon;
    int topDon;
    if (fgets(line, 100, source) == 1){
        sscanf(line, "%d %d", &nrDonors, &topDonors);
    }
    else{
        printf("No size given!\n");
        exit(1);
    }

}

Donor *readDonor(FILE *source, int *nrDonors, int *topDonors){
    Donor *donors = malloc(*nrDonors * sizeof(Donor));
    if (donors == NULL){
        printf("Mallocation Failed!");
        exit(1);
    }

    char line[100];
    

}

