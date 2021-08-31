#include <stdio.h>
#include <math.h>

int main() {
    int n, i, check = 1;
    scanf("%d", &n);
    if(n < 2) check = 0;
    for(i = 2; i <= sqrt(n); i++) {
        if(n%i == 0) {
            check = 0;
            break;
        }
    }
    if(check) printf("La so nguyen to");
    else printf("Khong la so nguyen to");
    return 0;
}