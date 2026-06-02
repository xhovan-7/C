#include "func.h"


int main(int argc, char *argv[]){
    FILE *source;
    source = fopen(argv[1], "r");
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