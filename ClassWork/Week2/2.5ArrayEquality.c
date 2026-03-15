#include <stdio.h>
#include <stdbool.h>

void scanList(int nums[], int nr){
    for (int i = 0; i < 5; i++){
        printf("Enter element %d of list %d:", i + 1, nr);
        scanf("%d", &nums[i]);
    }
}

bool equals (int a[], int b[]){
    for (int i = 0; i < 5; i++){
        if (a[i] != b[i]) 
            return false;
    }
    return true;
}

int main(){
    int nums1[5];
    int nums2[5];

    scanList(nums1, 1);
    scanList(nums2, 2);

    printf(equals(nums1, nums2) ? "True" : "False");


    return 0;
}