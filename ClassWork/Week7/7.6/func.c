#include "func.h"


int getSize(FILE *fp){
    char line[100];
    int count = 0;
    while (fgets(line, 100, fp) != NULL) count++;
    rewind(fp);
    return count;
}


void readData(FILE *fp, Student students[], int size){
    char line[100];
    /*
    for (int i = 0; i < size; i++){
        char c;
        int j = 0;
        while ((c = fgetc(fp)) != ';'){
            students[i].name[j] = c;
            j++;
        }
        students[i].name[j] = '\0';
        fgetc(fp);

        j = 0;
        while ((c = fgetc(fp)) != ';'){
            students[i].surname[j] = c;
            j++;
        }
        students[i].surname[j] = '\0';


        for (int j = 0; j < 4; j++){
            fscanf(fp, "%d", &students[i].grades[j]);
        }
        fgetc(fp);
    }

    */
    
    for (int i = 0; i < size; i++){
        fgets(line, 100, fp);
        
        //name
        char *ptr = line;
        char *len = strchr(line, ';');
        int offset = len - ptr;
        

        strncpy(students[i].name, line, offset);
        students[i].name[offset] = '\0';
        
        printf("[%d]:[%s][%d]", i + 1, students[i].name, offset);
        if (students[i].name[offset + 1] == '\0'){
            printf("['0']\n");
        } else {
            printf("NOT NULL\n");
        }


        //surname
        ptr += offset + 2;
        len = strchr(ptr, ';');
        
        offset = len - ptr;

        strncpy(students[i].surname, ptr, offset);
        students[i].surname[offset] = '\0';
        
        printf("[%d][%s][%d]", i + 1, students[i].surname, offset);
        if (students[i].surname[offset] == '\0'){
            printf("['0']\n");
        } else {
            printf("[NOT NULL]\n");
        
        }
        ptr += offset + 2;
        
        for (int j = 0; j < 4; j++){
            sscanf(ptr, "%d%n", &students[i].grades[j], &offset);
            ptr += offset;
            
            }
            printf("%d: %s %s %d %d %d %d\n", 
            i + 1,
            students[i].name,
            students[i].surname,
            students[i].grades[0],
            students[i].grades[1],
            students[i].grades[2],
                    students[i].grades[3]);
    }

getAvg(students, size);

}


void getAvg(Student students[], int size){
    for (int i = 0; i < size; i++){
        int sum = 0;
        for (int j = 0; j < 4; j++){
            sum += students[i].grades[j];
        }
        students[i].avg = sum / 4.0;
    }
}


void printStudent(Student students[], int size){
    for (int i = 0; i < size; i++){
        printf("%d: %s %s - %.2lf - %d %d %d %d \n", 
                    i + 1,
                    students[i].name,
                    students[i].surname,
                    students[i].avg,
                    students[i].grades[0],
                    students[i].grades[1],
                    students[i].grades[2],
                    students[i].grades[3]);
    }
}