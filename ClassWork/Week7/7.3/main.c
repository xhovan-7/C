#include "func.h"

int main(){
    int size;
    printf("Enter the number of employees: ");
    scanf("%d", &size);
    
    Employee e[size];

    readData(e, size);

    getSalary(e, size);

    printEmployes(e, size);

    Employee minSalary = findLowest(e, size);
    printLowestEmployee(minSalary);

    double avgSalary = averageSalary(e, size);
    printf("Average Salary: %.2lf$\n", averageSalary(e, size));

    printf("Number of employees with salary greater than the average: %d\n",
                                aboveAvg(e, size, averageSalary(e, size)));

    return 0;
}