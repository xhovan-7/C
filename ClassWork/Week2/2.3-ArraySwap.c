#include <stdio.h>

void swap (int x, int y){
    int temp = x;
    x = y;
    y = temp;
}

void swapFirstTwoInArray(int nums[]){
    int temp = nums[0];
    nums[0] = nums[1];
    nums[1] = temp;
}

void printList(int list[], int size){
    printf("[");
    for (int i = 0; i < size; i++){
        printf("%d", list[i]);
        if (i < size - 1) 
            printf(", ");
    }
    printf("]\n");
}

int main(){
    int nums[4] = {1, 2, 3, 4};

    printf("Before calling swap array is ");
    printList(nums, 4);

    swap(nums[0], nums[1]);

    printf("After calling swap array is ");
    printList(nums, 4);

    printf("Before calling swapFirstTwoInArray array is ");
    printList(nums, 4);

    swapFirstTwoInArray(nums);

    printf("After calling swapFirstTwoInArray array is ");
    printList(nums, 4);


    return 0;
}