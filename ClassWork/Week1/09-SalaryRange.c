#include <stdio.h>

int counter[9] = {0};


int main() {
    int size;
    double salary;
    int minRange[8] = {200, 300, 400, 500, 600, 700, 800, 900};
    int maxRange[8] = {299, 399, 499, 599, 699, 799, 899, 999};
    
    printf("Enter the number of sales people: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++){
        printf("$");
        scanf("%lf", &salary);

        salary = salary * 9 / 100 + 200;

        for (int j = 0; j < 8; j++){
            if (salary >= minRange[j] && salary <= maxRange[j]){
                counter[j]++;
            }
        }

        if (salary >= 1000) 
            counter[8]++;
    
    }
    
    for (int i = 0; i < 8; i++){
        printf("$%d - $%d %d \n", minRange[i], maxRange[i], counter[i]);
    }
    printf("$1000 >    %d", counter[8]);

    return 0;
}