#include <stdio.h>

void scanList (int nums[11]){
    printf("Enter 10 intigers: ");
    for (int i = 0; i < 10; i++){
        scanf("%d", &nums[i]);
    }
}

void indexInsert (int nums[], int index){
    for (int i = 10; i > index; i--){
        nums[i] = nums[i-1];
    }
    nums[index] = 10;
}

void printList (int nums[]){
    printf("Sample Output: ");
    for (int i = 0; i < 11; i++){
        printf("%d ", nums[i]);
    }
}

int main(){
    int nums[11];
    int index;

    scanList(nums);
    printf("Enter index: ");
    scanf("%d", &index);

    indexInsert(nums, index);

    printList(nums);


    return 0;
}