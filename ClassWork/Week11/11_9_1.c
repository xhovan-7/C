#include <stdio.h>
#include <stdlib.h>

void readList(double list[], int size){
    for(int i = 0; i < size; i++){
        scanf("%lf", &list[i]);
    }
}

void max12(double list[], int size, double *max1, double *max2){
    if(list[0] > list[1]){
        *max1 = list[0];
        *max2 = list[1];
    }else{
        *max1 = list[1];
        *max2 = list[0];
    }

    for(int i = 2; i < size; i++){ // 2, 4 ,3 ,2, 5, 
        if(list[i] > *max1){
            *max2 = *max1;
            *max1 = list[i];
        }
        else if(list[i] > *max2){
            *max2 = list[i];
        }
    }
}


int main(int argv, char *argc[]){
    int size;

    printf("Enter the size: ");
    scanf("%d", &size);

    double list[size];
    readList(list, size);

    double max1, max2;
    
    max12(list, size, &max1, &max2);

    printf("%.2lf %.2lf", max1, max2);

    return 0;
}