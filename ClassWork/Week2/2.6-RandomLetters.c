#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int count[26] = {0};

/*
void scanList(char letters[], int size){
    printf("Enter 100 lowercase letter: ");
    int i = 0;
    for (i = 0; i < size; i++){
        scanf(" %c", &letters[i]);
       while (letters[i] < 'a' && letters[i] > 'z'){
            printf("Invalid letter! Try again: ");
            scanf(" %c", &letters[i]);
        }
    }
    letters[i] = '\0';
}

*/


void printList(char letters[]){
    printf("The lowercase letters are:\n");
    for (int i = 0; letters[i] != '\0';i++){
        printf("%c ", letters[i]);
        if (i % 25 == 24) puts("");
    }
    puts("");
}

void randomLetters (char letters[]){
    int i;
    for (i = 0; i < 100; i++){
        letters[i] = rand() % 26 + 'a';
    }
    letters[i] = '\0';
}

void letterCount(char letters[], int count[]){
    for (int i = 0; letters[i] != '\0'; i++)
        count[letters[i] - 'a']++;
}

void printResult (int count[]){
    for (int i = 0; i < 26; i++){
        printf("%c - %d; ", i + 'a', count[i]);
        if (i % 13 == 12) puts("");
    }
}


int main(){
    char letters[101];
    srand(time(0));
    
//    scanList(letters, 100);
    randomLetters(letters);

    printList(letters);

    letterCount(letters, count);

    printResult(count);



    return 0;
}