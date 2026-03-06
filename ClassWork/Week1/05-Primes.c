#include <stdio.h>
#include <stdbool.h>
const int N = 50;

bool isPrime(int num){
    int div = 1; 
    int cnt = 0;

    while (num >= div){
        if ( num % div == 0){
            cnt++;
            if (cnt > 2) return false;
        }
        div++;
    }
    return true;
}

void printPrimes(int *prime){

    for (int i = 0; i < N; i++){
        printf("%d \t", prime[i]);
        if (i % 10 == 9) printf("\n");
    }

}



int main()
{
    int prime[N];
    int cnt = 0;
    int i = 0;
    int num = 2;
    int div = 1;

    while (i < N){

        if (isPrime(num)){
            prime[i] = num;
            i++;
        }

        num++;
    }

    printPrimes(prime);

    return 0;
}
