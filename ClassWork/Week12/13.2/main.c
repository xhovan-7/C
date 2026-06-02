#include <stdio.h>
#include <stdlib.h>
#include "func.h"


int main(){
    Student *head, *temp;
    temp = (sizeof(Student));

    int n;

    printf("Enter nr of students: ");
    scanf("%d", &n);

    Student *newNode;
    newNode = malloc(n * sizeof(Student));
    head = newNode;

    scanf("%15s %15s", &newNode->name, &newNode->surname);
    double sum = 0;
    int i;
    for (i = 0; i < 6; i++){
        int take;
        scanf("%d", &take);

        if (take == -1){
            break;
        }else{
            newNode->grades[i] = take;
            sum += take;
        }
    }

    newNode->avg = sum / i;

    


    return 0;
}