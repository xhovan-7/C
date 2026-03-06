#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    for (int i = 0; i < 20; i++){
        int roll = rand() % 6 + 1;
        printf("%d \t", roll);

        if ((i + 1) % 5 == 0)
            printf("\n");
    }

    return 0;
}
