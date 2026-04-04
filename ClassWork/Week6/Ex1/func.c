#include "func.h"


int getSize(FILE *source){
    int size;
    char line[100];

    fgets(line, 100, source);

    sscanf(line, "%d", &size);

    if(size <= 0 && size >100){
        return -1;
    }
    return size;
}

/*
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
*/

Student *readStudents(FILE *source, int size){

    fscanf(source, "%d", &size);

    Student *students = malloc((size + 1) * sizeof(Student));
    if (students == NULL) return NULL;
    else printf("Mallocation successfull!");

    for (int i = 0; i < size; i++){
        char line[101];
        fgets(line, 100, source);

        printf("%s", line);
        
        
        int j = 0;
        while(1){
            sscanf(line, "%d", &students[i].grades[j]);

            if (students[i].grades[j] == -999){
                students[i].grades[j] = 0;
                break;
            }
            else if(students[i].grades[j] <= 0 && students[i].grades[j] > 100){
                printf("Invalid Grade: %d", students[i].grades[j]);
                return NULL;
            }
            j++;
        }


        double sum = 0;
        for (int k = 0; k < j; k++){
            sum += students[i].grades[k];
        }
        students[i].avg = sum / j;
    }

    return students;
}

void sortByAvg(Student *students, int size){

    
    for (int i = 0; i < size - 1; i++){
        int min = i;

        for (int j = i + 1; j < size; j++){
            if (students[min].avg > students[j].avg){
                min = j;
            }
        }
        int k = 0;

        students[size]= students[i];
        students[i] = students[min];
        students[min] = students[size];

 /*       strcpy(temp.name, students[i].name);
        temp.avg = students[i].avg;
        do{
            temp.grades[k] = students[i].grades[k];
        }while (students[i].grades[k++] != 0);*/

    }
}

void printStudent(Student *students, int size){
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

double getTarget(){
    int target;
    printf("Enter the grade to search for: ");
    scanf("%d", &target);

    return target;
}

int binarySearch(Student *students, int size, double target){
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

void printTarget(Student *students, int size, int index, double target){
    printf("Student is at position %d\n", index + 1);

    printf("Students with average grater than or equal to %.2lf\n", target);

    for (int i = index, j = 0; i < size; i++, j++){
        printf("%d: %s - %.2lf\n", i + 1, students[i].name, students[i].avg);
    }

}
