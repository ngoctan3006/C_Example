#include <stdio.h>

int main() {
    int a[100], n, i, count = 0;
    float ave = 0, sum = 0;
    do {
        scanf("%d", &n);
    } while(n < 0 || n >= 100);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] > 0) sum += a[i];
        if(a[i] < 0) {
            ave += a[i];
            count++;
        }
    }
    printf("%f %f", ave/count, sum);
    return 0;
}