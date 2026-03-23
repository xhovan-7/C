#include <stdio.h>
#include "func.h"


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

    outfile = fopen(thema, "a");
    if (outfile == NULL){
        printf("File couldn't be created!");
        return 1;
    }
    
    copyFiles(src, outfile);

    appendText(outfile);

    fclose(src);
    fclose(outfile);

    return 0;
}