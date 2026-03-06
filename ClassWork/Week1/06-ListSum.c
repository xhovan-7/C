#include <stdio.h>

void scanList(int list[], int size){
    for (int i = 0; i < size; i++){
        scanf("%d", &list[i]);
    }
}

void printList(int list[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", list[i]);
    }
}


int main(void) {
    int size;
    int list1[10];
    int list2[10];
    int sum[10];

    printf("Nr of digits: ");
    scanf("%d", &size);

    scanList(list1, size);
    scanList(list2, size);

    for (int i = 0; i < size; i++){
        sum[i] = list1[i] + list2[i];
    }

    printList(sum, size);

    return 0;
}