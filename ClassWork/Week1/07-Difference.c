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


int main() {
    int size;
    int list[10];
    int min, max, diff;

    printf("Nr of digits: ");
    scanf("%d", &size);

    scanList(list, size);

    min = list[0];
    max = list[0];

    for (int i = 1; i < size; i++){
        if (min > list[i])
            min = list[i];
        
        else if (max < list[i])
            max = list[i];

    }

    diff = max - min;

    printf("%d", diff);

    return 0;
}