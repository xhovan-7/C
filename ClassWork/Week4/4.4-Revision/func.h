#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#define MAX_LENGTH  100

void thema_txt(char thema[]);

void copyFiles(FILE *src, FILE *outfile);

void appendText(FILE *outfile);


#endif