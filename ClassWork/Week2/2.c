#include <stdio.h>

//UNFINISHED!!!
void scanList(double list[], int size){
    for (int i = 0; i < size; i++){
        scanf("%lf", &list[i]);
    }
}

double minValue (double list[], int size){
    int min = list[0];
    for (int i = 1; i < size; i++){
        if (min > list[i]){
           min = list[i]; 
        }
    }

    return min;
}

int indexOfSmallestElement(double list[], int size){
    int min = list[0];
    for (int i = 1; i < size; i++){
        if (min > list[i]){
           min = i; 
        }
    }
}

double secMin (double array[], double min){

}

int main() {
    double list[10];
    int size = 10;
    double min;
    int minIndex;
    double secondMin;

    printf("Enter 10 numbers:");
    scanList(list, size);

    min = minValue(list,size);
    minIndex = indexOfSmallestElement(list, size);
    secondMin = secMin(list, size);

    printf("The minimum number is %lf", min);
    printf("Index of minimum number is %lf", min);
    printf("The minimum number is %lf", min);
    
    
    return 0;
}