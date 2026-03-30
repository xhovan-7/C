#include <stdio.h>

int power(int x, int y){
    if (y == 1)
        return x;

    return x * power(x, y - 1);
}


int main (){
    int x;
    int y;
    int result;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &x, &y);

    result = power(x, y);    

    printf("%d", result);

    return 0;
}