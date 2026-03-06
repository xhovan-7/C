#include <stdio.h>

int toDecimal(char ch){

    int digit;

    if (ch >= '0' && ch <= '9'){
            digit = ch - 48;
        }

        else if (ch >= 'a' && ch <= 'f'){
            digit = ch - 87;
        }

        else if (ch >= 'A' && ch <= 'F'){
            digit = ch - 55;
        }

        return digit;
}

int main()
{
    char number[10];
    int decimal;
    int reverse = 0;
    int i = 0;

    printf("Enter number: ");
    scanf("%s", number);

    while (number[i] != '\0'){
        
        int digit = toDecimal(number[i]);

        reverse = reverse * 16 + digit;

        i++;
    }

    printf("%d", reverse);

    return 0;
}
