#include <stdio.h>

void scanList(double list[], int size){
    for (int i = 0; i < size; i++){
        scanf("%lf", &list[i]);
    }
}

void minValue (double list[], int size, double *min, int *minIndex, double *secondMin){
    *min = (list[0] < list[1] ? list[0] : list[1]);
    *secondMin = (list[0] > list[1] ? list[0] : list[1]);
    *minIndex = (list[0] < list[1] ? 0 : (list[0] > list[1] ? 1 : 0));
    
    for (int i = 2; i < size; i++){
        if (*min > list[i]){
            *secondMin = *min;
            *min = list[i];
            *minIndex = i; 
        }
    }
}


int main() {
    double list[10];
    int size = 10;
    double min;
    int minIndex;
    double secondMin;

    printf("Enter 10 numbers:");
    scanList(list, size);

    minValue(list,size, &min, &minIndex, &secondMin);


    printf("The minimum number is %.2lf\n", min);
    printf("Index of minimum number is %d\n", minIndex);
    printf("The second minimum is %.2lf\n", secondMin);
    
    
    return 0;
}