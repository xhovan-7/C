#include "func.h"

int main(){
    int size;
    printf("Enter the number of employees: ");
    scanf("%d", &size);
    
    Employee e[size];

    readData(e, size);

    getSalary(e, size);

    Employee min = findLowest(e, size);

    double avgSalary = averageSalary(e, size);


    return 0;
}