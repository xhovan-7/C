#include <stdio.h>

struct Student{
    char name[20];
    int id;
    int grades[3];
    float avg;
};

void readData(struct Student st[], int size){
    
    for (int i = 0; i < size; i++){
        int sum = 0;
        scanf("%s %d", st[i].name, &st[i].id);
        for (int j = 0; j < 3; j++){
            scanf("%d", &st[i].grades[j]);
            sum += st[i].grades[j];
        } 
        st[i].avg = sum / 3.0;
    }
}

struct Student findMax(struct Student st[], int size){
    int maxIndex = 0;
    for (int i = 1; i < size; i++){
        if (st[maxIndex].avg < st[i].avg){
            maxIndex = st[i].avg;
            maxIndex = i;
        }
    }
    return st[maxIndex];
}

void sortArray(struct Student students[], int size){
    
    for (int i = 1; i < size - 1; i++){
        int maxIndex = i;
        for (int j = i + 1; j < size; j++){
	        if (students[maxIndex].avg < students[j].avg){
 	           maxIndex = j;
            }
        }
        struct Student temp = students[maxIndex];
        students[maxIndex] = students[i];
        students[i] = temp;
    }
}

void sortArrayByGrade(struct Student students[], int size, int index){
    
    for (int i = 1; i < size - 1; i++){
        int maxIndex = i;
        for (int j = i + 1; j < size; j++){
	        if (students[maxIndex].grades[index] < students[j].grades[index]){
 	           maxIndex = j;
            }
        }
        struct Student temp = students[maxIndex];
        students[maxIndex] = students[i];
        students[i] = temp;
    }
}


int main(){
    int size;
    scanf("%d", &size);
	struct Student students[size];
    readData(students, size);    
    
    int gradePosition;
    puts("Enter the position of the grade do you want to sort by");
    scanf("%d", &gradePosition);
    sortArrayByGrade(students, size, gradePosition - 1);
    
     
    
    
    return 0;
}