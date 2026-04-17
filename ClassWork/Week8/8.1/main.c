#include "func.h"


int main(){
    FILE *fp;
    fp = fopen("data.txt", "r");
    
    int stdSize;
    int gradeSize;
    getSize(fp, &stdSize, &gradeSize);

    Student *students = createStudent(stdSize, gradeSize);

    



    free_students(students);

    return 0;
}