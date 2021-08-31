#include <stdio.h>

int  main() {
    int n, r = 1;
    do {
        scanf("%d", &n);
    } while(n < 0 || n >= 8);
    for(int i = 2; i <= n; i++)
        r *= i;
    printf("%d", r);
    return 0;
}