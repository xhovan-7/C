#include <stdio.h>
#include <string.h>
int MAX_LENGTH = 100;

void thema_txt(char thema[]){
    char temp[20];
    int len;
    
    printf("Enter the review thema: ");
    fgets(temp, 19, stdin);
    len = strlen(temp);
    if (temp[len - 1] == '\n'){
        temp[len - 1] = '\0';
    }
    sprintf(thema, "%s.txt", temp);
}

void copyFiles(FILE *src, FILE *outfile){
    char line[MAX_LENGTH + 1];

    while (fgets(line, MAX_LENGTH, src) != NULL){
        fprintf(outfile, "%s\n", line);
    }
}

void appendText(FILE *outfile){
    char line[MAX_LENGTH + 1];
    
    printf("Enter below the text to append in your review: (type end in a new line to end)\n");
    while ((fgets(line, MAX_LENGTH, stdin) != NULL) && (strcmp(line, "end") != 0)){
        fprintf(outfile, "%s\n", line);
    }
}

int main(){
    FILE *src;
    src = fopen("source.txt", "r");
    if (src == NULL){
        printf("File doesn't exist!");
        return 1;
    }

    char thema[24]; 
   
    thema_txt(thema);

    FILE *outfile;

    outfile = fopen(thema, "w");

    copyFiles(src, outfile);

    appendText(outfile);

    fclose(src);
    fclose(outfile);

    return 1;
}