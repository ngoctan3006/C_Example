#include <stdio.h>

int main() {
    int a, mu, i = 2;
    scanf("%d", &a);
    printf("%d = ", a);
    while(a != 1) {
        mu = 0;
        while(a%i == 0) {
            mu++;
            a /= i;
        }
        if(mu) {
            if(mu > 1) printf("%d^%d", i, mu);
            else printf("%d", i);
            if(a > i) printf(" x ");
        }
        i++;
    }
    return 0;
}