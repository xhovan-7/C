#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *in;
    in=fopen("input.txt","r");

    if(in==NULL){
        printf("File not found");
        return 1;
    }

    FILE *out;
    out=fopen("output.txt","w");
    if(out==NULL){
        printf("File not found");
        return 1;
    }

    int n;

    fscanf(in,"%d",&n);
    int m;
    fscanf(in,"%d",&m);
    struct Student s[n];
    readData(s,n,m,in);


    printData(s,n,m,out);
    fclose(in);
    fclose(out);

    return 0;
}