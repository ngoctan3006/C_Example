#include <stdio.h>

int main() {
    int n, a[10000], i, j;
    do {
        scanf("%d", &n);
    } while(n < 0 || n >= 10000);
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++)
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
    for(i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}