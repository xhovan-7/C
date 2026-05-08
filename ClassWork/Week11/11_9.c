#include <stdio.h>
#include <stdlib.h>

int getSize(int size)
{    
    printf("How many numbers? ");
    scanf("%d", &size);
    
    return size;
}

void getData(float list[], int size)
{
    printf("Enter numbers: ");
    
    for (int i = 0; i < size; i++)
    {
        scanf("%f", &list[i]);
    }
    
}

void max12(float list[], int size, float *max1, float *max2)
{
    *max1 = (list[0] > list[1] ? list[0] : list[1]);
    *max2 = (list[0] < list[1] ? list[0] : list[1]);

    for(int i = 2; i < size; i++){
        if(list[i] > *max1){
             *max2 = *max1;
             *max1 = list[i];
        }
        else if(list[i] > *max2){
            *max2 = list[i];
        }
    }
}

int main(){
    float list[20];
    float max1;
    float max2;
    int size = getSize(size);

    getData(list, size);

    max12(list, size, &max1, &max2);

    printf("Max nr is: %.2f \nSecond max is %.2f", max1, max2);

    return 0;
}