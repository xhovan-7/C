#include "func.h"


int main(){
    int size = getSize();

    Subject subjects[2];
    readSubject(subjects, 2);

    Student students[size];
    readData(students, size, subjects);

    printStudents(students, size, subjects);

    printMax(students, size);




    return 0;
}