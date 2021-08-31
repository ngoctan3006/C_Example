#include <stdio.h>
#include <math.h>

int prime(long long n) {
    if(n < 2) return 0;
    long long sq = sqrt(n);
    for(long long i = 2; i <= sq; i++)
        if(n%i == 0) return 0;
    return 1;
}

int main() {
    long long a[100], sum = 0;
    int n, i, count = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(prime(a[i])) {
            sum += a[i];
            count++;
        }
    }
    if(count) printf("%.1lf", (double)sum/count);
    else printf("Error");
    return 0;
}