#include <stdio.h>
#include <stdlib.h>

void uppercase(char *p){

    for(; *p != '\0';p++){
        if (*p == ' ') continue;
        *p -= 32;
    }


}

int main(){
    char name[20];
    printf("Enter the word in lowercase:");
    scanf("%19[^\n]", name);
    char *p = name;
    uppercase(p);
    printf("%s", name);

    
    return 0;
}