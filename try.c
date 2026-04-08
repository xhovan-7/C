#include <stdio.h>

struct Student(){
    char name[20];
    int id;
    int grades[3];
    float avg;
};

void readData(Student st[], int size){
    
    for (int i = 0; i < size; i++){
        int sum = 0;
        scanf("%s %d", st[i].name, &st[i].id);
        for (int j = 0; j < 3; j++){
            scanf("%d", &st[i].grade[j]);
            sum += st[i].grade[j];
        } 
        st[i].avg = sum / 3.0;
    }
}

struct Student findMax(struct Student st[], int size){
    int maxIndex = 0;
    for (int i = 1; i < size; i++){
        if (st[max].avg < st[i].avg){
            max = st[i].avg;
            maxIndex = i;
        }
    }
    return st[max];
}

void sortArray(struct Student arr[], int size){
    
    for (int i = 1; i < size - 1; i++){
        int maxIndex = i;
        for (int j = i + 1; j < size; j++){
	        if (st[max].avg < st[j].avg){
 	           maxIndex = j;
            }
        }
        struct Student temp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = temp;
    }
}

void sortArrayByGrade(struct Student arr[], int size, int index){
    
    for (int i = 1; i < size - 1; i++){
        int maxIndex = i;
        for (int j = i + 1; j < size; j++){
	        if (st[max].grade[index] < st[j].grade[index]){
 	           maxIndex = j;
            }
        }
        struct Student temp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = temp;
    }
}


int main(){
    int size;
    scanf("%d", &size);
	struct Student an[size];
    readData(an, size);    
    
    int gradePosition;
    puts("Enter the position of the grade do you want to sort by");
    scanf("%d", &gradePosition);
    sortArrayByGrade(an, size, gradePosition - 1);
    
     
    
    
    return 0;
}