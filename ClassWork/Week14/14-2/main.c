#include <stdio.h>
#include <stdlib.h>

int main(int args, char *argv[]){
    if (args != 3){
        printf("Incorrect number of arguments!\n");
        return 1;
    }    

    FILE *infile = NULL, *outfile = NULL;

    infile = fopen(argv[1], "r");
    outfile = fopen(argv[2], "w");

    if (infile == NULL){
        puts("File failed to open!");
        return 1;
    }

    if(outfile == NULL){
        puts("File failed to create!");
        return 1;
    }

    char line[256];

    while(fgets(line, 256, infile) != NULL){
    fputs(line, outfile);
    }

    return 0;
}