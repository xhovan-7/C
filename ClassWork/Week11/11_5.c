#include <stdio.h>
#include <stdlib.h>


int main(){
    int array[5] = {0, 1, 2, 3, 4};
    int *p = array;

    printf("The location of the first element: %p, it's value %d\n", p, *p);


    p += 1;
    printf("The location of the third element: %p, it's value %d\n", p, *p);
    
    printf("The location of the third element: %p, it's value %d\n", p + 3, *(p + 3));


    return 0;
}