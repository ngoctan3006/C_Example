#include <stdio.h>

int  main() {
    int a, b;
    do {
        scanf("%d", &a);
    } while(a < 0);
    do {
        scanf("%d", &b);
    } while(b < 0);
    int tich = a*b;
    while(a != b) {
        if(a > b) a -= b;
        else b -= a;
    }
    printf("%d\n%d", a, tich/a);
    return 0;
}