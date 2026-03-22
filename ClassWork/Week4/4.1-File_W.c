#include <stdio.h>
FILE *outfile;


int main(){
    outfile = fopen("4.1-output.txt",  "w+");
    int value;
    char name[20];
    char line[100];
    int i = 0;
    int j = 0;

    if (!outfile){
        printf("Unable to create file!");
        return 0;
    }

    while(1){
        printf("%d: ", i + 1);
        scanf("%s", name);
        if(name[0] == '-' && name[1] == '1') break;
        scanf("%d", &value);

        if(name[0] == '-' && name[1] == '1') break;
        if (value == -1) break;

        if (value >= 10 && value <= 20){
            fprintf(outfile, "%d: %s - %d\n", j + 1, name, value);
            j++;
        }

        i++;
    }

    rewind(outfile);

    while (fgets(line,sizeof(line), outfile) != NULL){
        printf("%s", line);
    }
    
    fclose(outfile);



    return 0;
}