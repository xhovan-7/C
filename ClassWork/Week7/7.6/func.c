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

    for (int i = 0; i < size; i++){
        fgets(line, 100, fp);
        
        char *ptr = line;
     //   int offset = 0;
        char *len = strchr(line, ';');
        int offset = len - ptr;

        strncpy(students[i].name, line, offset);
        printf("[%s]", students[i].name);

        ptr += offset + 2;
        len = strchr(ptr, ';');
        offset = len - ptr;
        printf("\noffset = %d, *len %p *ptr %p\n", offset, (void *)len, (void *)ptr);
        strncpy(students[i].surname, ptr, offset);
        printf("[%s]", students[i].surname);

        ptr += offset + 2;

        for (int j = 0; j < 4; j++){
            sscanf(line, "%d%n", &students[i].grades[j], &offset);
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