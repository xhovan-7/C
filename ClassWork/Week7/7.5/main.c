#include "func.h"


int main(){
    FILE *fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL){puts("File failed to open!"); return 1;}

    int size = getSize(fp);
    if (size == 0){ puts("Empty file!");    return 1;   }

    Donor donors[size];

    readData(fp, donors, size);

    fclose(fp);
    
    Donor maxDonor = findMax(donors, size);
    printDonor(maxDonor);

    Donor secondMax = findSecond(donors, size);
    printDonor(secondMax);

    return 0;
}