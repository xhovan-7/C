#include "func.h"


int getSize(){
    int size;
    printf("Enter the number of employees:");
    scanf("%d", &size);
    return size; 
}


void readData(LeaveRecord emp[], int size){
    for (int i = 0; i < size; i++){
        printf("Enter staff ID, total leave days, and leave days taken for employee %d: ", i + 1);
        scanf("%d %d %d",   &emp[i].id, 
                            &emp[i].totalLeave,
                            &emp[i].leaveTaken);
    }
}


void getLeft(LeaveRecord emp[], int size){
    for (int i = 0; i < size; i++)
    {
        emp[i].leaveLeft = emp[i].totalLeave - emp[i].leaveTaken;
        printf("Total Days(%d) - LeaveTaken(%d) = LeaveLeft(%d)", 
            emp[i].totalLeave, emp[i].leaveTaken, emp[i].leaveLeft);
    }
    
}

void checkHolidays(LeaveRecord emp[], int size){
    int checkId;
    int day;
    printf("Enter stadd ID to request leave: ");
    scanf("%d", &checkId);
    
    printf("Enter number of leave days requested: ");
    scanf("%d", &day);

    int id = 0;

    for (int  i = 0; i < size; i++){
        if (emp[i].id == checkId){
            id = i;
        }
    }

    if (id == 0){
        printf("No ID match in the system!\n");
        return;
    }

    if (emp[id].leaveLeft >= day){
        printf("Leave request accepted!");
    }
    else{
        printf("Leave request denied!");
    }

}


void printEmployee(LeaveRecord emp[], int size){
    for (int i = 0; i < size; i++){
        printf("%d: Employee ID: %d,\tTotal Leave %d,\tLeave Taken: %d,\tLeave Left: %d ", 
            i + 1, emp[i].id, emp[i].totalLeave, emp[i].leaveTaken, emp[i].leaveLeft);
    }
}