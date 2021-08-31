#include <stdio.h>

int main() {
    int n;
    do {
        printf("Input n: ");
        scanf("%d", &n);
        if(n%2 == 0) printf("You must type the value of odd number. ");
    } while (n%2 == 0);
    int k = 0;
    while((2*k+1) <= n) {
        printf("\nSize of triangle: %d\n", 2*k+1);
        for(int i = k; i >= 0; i--) {
            for(int j = 2*k+1; j >= 0; j--) {
                if(j >= k+1-i && j <= k+1+i) printf("*");
                else printf(" ");
            }
            printf("\n");
        }
        k++;
    }
    return 0;
}