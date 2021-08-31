#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if(n < 2) return 0;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n%i == 0) return 0;
    }
    return 1;
}

int main() {
    int n, i, check = 1;
    scanf("%d", &n);
    if(isPrime(n)) printf("it is a prime number");
    else printf("it is not a prime number");
    return 0;
}