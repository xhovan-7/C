#include "func.h"

void readData(Employee e[], int size){
    for (int i = 0; i < size; i++){
        printf("Enter details for employee %d:\n", i + 1);

        printf("Name: ");
        scanf("%19s", e[i].name);

        printf("Position: ");
        scanf("%19s", e[i].position);
        
        printf("Sales for the month: ");
        scanf("%lf", &e[i].sales);
        
        printf("City: ");
        scanf("%19s", e[i].addr.city);

        printf("Street: ");
        scanf("%19s", e[i].addr.street);

        printf("\n\n");
    }
}

void getSalary(Employee e[], int size){
    for (int i = 0; i < size; i++){
        e[i].salary = 600.0 + e[i].sales * 9.0 / 100.0;
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
    double sum = 0;

    for (int i = 0; i < size; i++){
        sum += e[i].salary;
    }
    return sum / size; 
}

int aboveAvg(Employee e[], int size, double avgSalary){
    int count = 0;
    for (int i = 0; i < size; i++){
        if (e[i].salary > avgSalary){
            count++;
        }
    }

    return count;
}

void printLowestEmployee(Employee e){
    printf("Employee with the lowest salary live in:\nCity: %s\nStreet: %s\n", e.addr.city, e.addr.street);
}

void printEmployes(Employee e[], int size){
    for (int i = 0; i < size; i++){
        printf("Employee %d:\nName %s\nPosition: %s\nSales: %.2lf$\nCity: %s\nStreet: %s\nTotal Salary: %.2lf$\n\n",
                i + 1, e[i].name, e[i].position, e[i].sales, e[i].addr.city, e[i].addr.street, e[i].salary);
    }
}