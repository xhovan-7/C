#include "func.h"


int getSize(FILE *fp){
    char line[100];
    int count = 0;
    while (fgets(line, 100, fp) != NULL){
        count++;
    }
    rewind(fp);
    return count;
}


void readData(FILE *fp, Donor donors[], int size){
    char line[100];
    for (int  i = 0; i < size; i++){
        fgets(line, 100, fp);
        sscanf(line, "%11s %11s %lf", 
            donors[i].name, 
            donors[i].surname, 
            &donors[i].amountDonated);
    }
}


Donor findMax(Donor donors[], int size){
    int max = 0;

    for (int i = 1; i < size; i++){
        if (donors[max].amountDonated < donors[i].amountDonated)
            max = i;
    }
    return donors[max];
}


Donor findSecond(Donor donors[], int size){
    int max;
    int second;
    if (donors[0].amountDonated > donors[1].amountDonated){
        max = 0;
        second = 1;
    }
    else{
        max = 1;
        second = 0;
    }
    
    for (int i = 0; i < size; i++){
        if (donors[second].amountDonated < donors[i].amountDonated){
            if (donors[max].amountDonated < donors[i].amountDonated){
                second = max;
                max = i;
            }
            else{
                second = i;
            }
        }
    }

    return donors[second];
}



void printDonor(Donor d){
    printf("%s %s %.2lf\n", d.name, d.surname, d.amountDonated);
}