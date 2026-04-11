#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdlib.h>

typedef struct LeaveRecord{
    int id;
    int totalLeave;
    int leaveTaken;
    int leaveLeft;
}LeaveRecord;

int getSize();

void readData(LeaveRecord emp[], int size);

void getLeft(LeaveRecord emp[], int size);

void checkHolidays(LeaveRecord emp[], int size);

void printEmployee(LeaveRecord emp[], int size);

#endif