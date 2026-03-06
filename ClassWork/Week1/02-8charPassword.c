#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    char pass[9];

    for (int i = 0; i < 3; i++){
        pass[i] = 65 + rand() % 26;
    }

    for (int i = 3; i < 6; i++){
        pass[i] = 97 + rand() % 26;
    }

    for (int i = 6; i < 8; i++){
        pass[i] = 48 + rand() % 10;
    }

    printf("%s", pass);

    

    return 0;
}
