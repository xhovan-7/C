#include <stdio.h>

void zeroList(int nrStudents, int list[]){
    for (int i = 0; i < nrStudents; i++){
        list[i] = 0;
    }
}

void printResult (int nrStudents, int score[]){
    for (int i = 0; i < nrStudents; i++){
        printf("Student %d's correct answer is %d\n", i+1, score[i]);
    }
}

void scanString(int nrQuestions, char list[]){
    for (int i = 0; i < nrQuestions; i++){
        scanf(" %c", &list[i]);
/*        while (list[i] < 'A' && list[i] > 'E'){
            printf("Invalid Answer!\nEnter a letter from 'A' to 'E'");
            scanf("%c", &list[i]);
        }
*/    }
    list[nrQuestions] = '\0';
}

int compareAnswer (char list[], char answer[]){
    int cnt = 0;
    for (int i = 0; list[i] != '\0'; i++){
        if (list[i] == answer[i])
            cnt++;
    }
    return cnt;
}

int main(){
    int nrQuestions;
    int nrStudents;

    printf("Enter number of Questions:");
    scanf("%d", &nrQuestions);

    printf("Enter nr of Students:");
    scanf("%d", &nrStudents);

    char answer[nrQuestions + 1];
    char students[nrStudents][nrQuestions + 1];
    int score[nrStudents];

    zeroList(nrStudents, score);
    printf("Answer Key:");
    scanString(nrQuestions, answer);


    for (int i = 0; i < nrStudents; i++){
        printf("%d. Student:", i+1);
        scanString(nrQuestions, students[i]);
        score[i] = compareAnswer(students[i], answer);        
    }

    printResult(nrStudents, score);

    return 0;
}