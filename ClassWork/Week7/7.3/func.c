#include "func.h"

void readData(Employee e[], int size){
    for (int i = 0; i < size; i++){
        printf("Enter details for employee %d", i + 1);

        printf("Name: ");
        scanf("%19s", e[i].name);

        printf("Position: ");
        scanf("%19s", e[i].position);
        
        printf("Sales for the month: ");
        scanf("%d", e[i].sales);
        
        printf("City: ");
        scanf("%19s", e[i].addr.city);

        printf("Street: ");
        scanf("%19s", e[i].addr.street);
    }
}

void getSalary(Employee e[], int size){
    for (int i = 0; i < size; i++){
        e[i].salary = 600.0 + e[i].sales * 9 / 100;
    }
}

Employee findLowest(Employee e[], int size){
    int min = 0;
    for (int i = 1; i < size; i++){
        if (e[min].salary > e[i].salary) min = i;
    }

    return e[min];
}

double averageSalary(Employee e[], int size){
    double avg = 0;

    for (int i = 0; i < size; i++){

        
    }
}

int aboveAvg(Employee e[], int size, double avgSalary){

}