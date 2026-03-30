#include <stdio.h>

double thyesaAddition(double f){
    if (f == 1)
        return 1;

    return thyesaAddition(f - 1) + (1 / f);
}


int main(){
    double f;
    double result;
    printf("Enter an int:");
    scanf("%lf", &f);

    result = thyesaAddition(f);

    printf("%lf", result);



    return 0;
}