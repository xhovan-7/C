#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>


typedef struct Address{
    char city[20];
    char street[20];
}Address;

typedef struct Employee{
    char name[20];
    char position[20];
    double sales;
    double salary;
    Address addr;
}Employee;


void readData(Employee e[], int size);

void getSalary(Employee e[], int size);

Employee findLowest(Employee e[], int size);

double averageSalary(Employee e[], int size);

int aboveAvg(Employee e[], int size, double avgSalary);

void printLowestEmployee(Employee e);

void printEmployes(Employee e[], int size);

#endif