#include <stdio.h>
#include <stdlib.h>

void allInOne(int *p_x, int *p_y, int *p_sum, int *p_product, int *p_division){
    *p_sum = *p_x + p_y;
    *p_product = *p_y * *p_x;
    *p_division = (float)*p_x / *p_y;
}




int main(){
    int x, y;
    int sum; 
    int product;
    float division;

    printf("Enter 2 numbers: ");
    scanf("%d %d", &x, &y); 

    allInOne(&x, &y, &sum, &product, &division);


    puts("HII");
    printf("The sum of the numbers is %d\n", sum);
    printf("The product of the numbers is %d\n", product);
    printf("The division of the numbers is %f\n", division);
    


    return 0;
}