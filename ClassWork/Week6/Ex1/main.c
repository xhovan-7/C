#include <stdio.h>
#include <string.h>


int getSize(){
    int size;

    printf("Enter the number of students: ");
    scanf("%d", &size);

    while(size <= 0 && size >100){
        printf("Enter a number between 1 - 100: ");
        scanf("%d", &size);
    }
    return size;
}

double getTarget(){
    double target;
    printf("Enter the grade to search for: ");
    scanf("%lf", &target);

    while(target <= 0 && target > 100){
        printf("Enter a grade between 1 - 100: ");
        scanf("%d", &target);
    }
    return target;
}

typedef struct Student{
    char name[16];
    double avg;
    int grades[100];
}Student;

void getNameGrades(Student students[], int size){

    for (int i = 0; i < size; i++){
        printf("%d: ", i);
        scanf("%s", students[i].name);

        int j = 0;
        while(1){
            scanf("%d", &students[i].grades[j]);

            if (students[i].grades[j] == -999){
                students[i].grades[j] = 0;
                break;
            }
            j++;
        }


        double sum = 0;
        for (int k = 0; k < j; k++){
            sum += students[i].grades[k];
        }
        students[i].avg = sum / j;
        }
}

void sortByAvg(Student students[], int size){

    for (int i = 0; i < size - 1; i++){
        int min = i;

        for (int j = i + 1; j < size; j++){
            if (students[min].avg > students[j].avg){
                min = j;
            }
        }
        int k = 0;

        Student temp;
        temp= students[i];
        students[i] = students[min];
        students[min] = temp;


 /*       strcpy(temp.name, students[i].name);
        temp.avg = students[i].avg;
        do{
            temp.grades[k] = students[i].grades[k];
        }while (students[i].grades[k++] != 0);*/


    }
}

void printStudent(Student students[], int size){
    for (int i = 0; i < size; i++){
        printf("%d: %s- avg: %.2lf, Grades: ", i + 1, students[i].name, students[i].avg);
        for (int j = 0; ;j++){
            if (students[i].grades[j] == 0){
                printf(". \n");
                break;
            }

            printf("%d, ", students[i].grades[j]);
        }
    }
}

int binarySearch(Student students[], int size, double target){
    int left = 0;
    int right = size - 1;
    int result = -1;

    while(left <= right){
        int mid = (left + right) / 2;

        if (students[mid].avg >= target){
            right = mid - 1;
            result = mid;
        }

        else if (students[mid].avg < target){
            left = mid + 1;
        }
    }

    return result;
}

void printTarget(Student students[], int size, int index, double target){
    printf("Student is at position %d\n", index + 1);

    printf("Students with average grater than or equal to %.2lf\n", target);

    for (int i = index, j = 0; i < size; i++, j++){
        printf("%d: %s - %.2lf\n", i + 1, students[i].name, students[i].avg);
    }

}

int main(){
    int size;
    size = getSize();

    Student students[100];

    getNameGrades(students, size);

    sortByAvg(students, size);

    double target = getTarget();

    int targetIndex = binarySearch(students, size, target);

    printTarget(students, size, targetIndex, target);



    return 0;
}
