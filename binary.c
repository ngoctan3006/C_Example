#include <stdio.h>
#include <math.h>

int main() {
    int a, n;
    scanf("%d%d", &a, &n);
    int d = (int) pow(2, n-1);
    for(int i = 0; i < n; i++) {
        printf("%d", a&d ? 1:0);
        d >>= 1;
    }
    return 0;
}