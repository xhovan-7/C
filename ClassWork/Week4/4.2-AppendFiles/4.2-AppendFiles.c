#include <stdio.h>
#include <string.h>

void appendString(FILE *append){
    int cnt = 0;
    char name[101];
    printf("Enter strings: \n");
    
    while (1){
        scanf("%100s", name);
        if (strcmp(name, "final") == 0){
            printf("%d lines added to the file!", cnt++);
            return;
        }

        if (strlen(name) < 10 && name[0] == 'a'){
            fprintf(append, "%s\n", name);
            cnt++;
        }
    }
    
}

int main(){
    FILE *append;
    append = fopen("data.txt", "a");
    if (append == NULL){
        printf("File couldn't be opened!\n");
        return 1;
    }

    appendString(append);

    


    return 1; 
}