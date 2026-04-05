#include <stdio.h>
#include <stdlib.h>
#include "func.h"



int main(){
    FILE *source;
    source = fopen("data2.txt", "r");
    if (source == NULL){
        printf("Error opening file!\n");
        return 1;
    }

    int nrDonors;
    int topDonors;

    getSize(source, &nrDonors, &topDonors);

    Donor *donors = readDonor(source, nrDonors);

    fclose(source);

    sortDescending(donors, nrDonors);

    printf("Top donors: \n");
    printDonors(donors, topDonors);




    free(donors);

    return 0; 
}