#include <stdio.h>
#include "func.h"

int main(){
    int size = getSize();
    
    LeaveRecord emp[size];

    readData(emp, size);

    checkHolidays(emp, size);


    return 0;
}