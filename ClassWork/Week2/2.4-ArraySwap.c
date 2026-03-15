#include <stdio.h>

void scanList(double nums[], int size){
    printf("Enter %d numbers: ", size);
    for (int i = 0; i < size; i++){
        scanf("%lf", &nums[i]);
    }
}

void printList(double nums[], int size){
    printf("The reversed numbers: ");
    for (int i = 0; i < size; i++){
        printf("%.1lf ", nums[i]);
    }
}

void reverseList(double nums[], int size){
    for (int i = 0, j = size - 1; i < (float)size / 2.0; i++, j--){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

int main(){
    double nums[10];

    scanList(nums, 10);

    reverseList(nums, 10);

    printList(nums, 10);


    return 0;
}