#include <stdio.h>

void scanList ( int list[], int size){
    for (int i = 0; i < size; i++){
        scanf("%d", &list[i]);
    }
}

void printList (int list[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}

void doubleList ( int list[], int size){
    for (int i = 0; i < size; i++){
        list[i] *= 2;
    }
}

int doubleElement (int e){
    
    return e * 2;
}


int main() {
    int list[10];
    int size;

    printf("Enter size:");
    scanf("%d", &size);

    printf("Enter elements of the array: ");
    scanList(list,size);

    printf("Values of the original arary are: ");
    printList(list, size);

    doubleList(list, size);

    printf("Values of the modified arary are: ");
    printList(list, size);

    printf("The value of a[3] is %d \n", list[3]);

    printf("The value in doubleElement is %d\n", doubleElement(list[3]));
    
    printf("The value of a[3] is %d\n", list[3]);


    return 0;
}