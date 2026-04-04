#include <stdio.h>
#include <stdlib.h>
#include "func.h"



int main(){
    FILE *source;
    source = fopen("data1.txt", "r");
    if (source == NULL){
        printf("Error opening file!\n");
        return 1;
    }

    int nrDonors;
    int topDonors;

    getSize(source, &nrDonors, &topDonors);

    Donor *donors = readDonor(source, nrDonors, topDonors);



    return 0; 
}