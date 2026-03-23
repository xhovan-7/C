#include <stdio.h>
#include <string.h>
#include "func.h"

void thema_txt(char thema[]){
    char temp[20];
    int len;
    
    printf("Enter the review thema(one word only): ");
    scanf("%19s", temp);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
       
    sprintf(thema, "%s.txt", temp);
}

void copyFiles(FILE *src, FILE *outfile){
    char line[MAX_LENGTH + 1];

    while (fgets(line, MAX_LENGTH + 1, src) != NULL){
        fprintf(outfile, "%s", line);
    }
}

void appendText(FILE *outfile){
    char line[MAX_LENGTH + 1];
    char endline[5] = "end\n";
    
    printf("Enter below the text to append in your review: (type end in a new line to end)\n");
    while ((fgets(line, MAX_LENGTH, stdin) != NULL) && (strcmp(line, endline) != 0)){
        fprintf(outfile, "%s", line);
    }
}