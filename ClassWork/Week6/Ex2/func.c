#include <stdio.h>
#include <stdlib.h>
#include "func.h"



void getSize(FILE *source, int *nrDonors, int *topDonors){
    char line[100];
    int nrDon;
    int topDon;
    if (fgets(line, 100, source)){
        sscanf(line, "%d %d", &nrDon, &topDon);
        *nrDonors = nrDon;
        *topDonors = topDon;
    }
    else{
        printf("No size given!\n");
        exit(1);
    }

}

Donor *readDonor(FILE *source, int size){
    Donor *donors = malloc((size + 1) * sizeof(Donor));
    if (donors == NULL){
        printf("Mallocation Failed!\n");
        exit(1);
    }

    char line[100];
    
    int i = 0;
    while(fgets(line, 100, source)){
        sscanf(line, "%12s %12s %f", donors[i].name, donors[i].surname, &donors[i].donatedMoney);
        i++;
    }

    return donors;
}

void sortDescending(Donor *donors, int size){
    
    for(int i = 0; i < size - 1; i++){
        int max = i; 

        for (int j = i + 1; j < size; j++){
            if (donors[max].donatedMoney < donors[j].donatedMoney){
                max = j;
            }
        }
        donors[size] = donors[max];
        donors[max] = donors[i];
        donors[i] = donors[size];
    }
}

void printDonors(Donor *donors, int size){

    for (int i = 0; i < size; i++){
        printf("%d %s %s: %.2f $\n", i + 1, donors[i].name, donors[i].surname, donors[i].donatedMoney);
    }
}

