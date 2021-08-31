#include <stdio.h>
#include <math.h>

int  main() {
    int n, i;
    double x, s1 = 0, s2 = 0, s3 = 0;
    do {
        scanf("%d", &n);
    } while(n < 0);
    scanf("%lf", &x);
    for(i = 0; i <= n; i++) s1 += pow(x, i);
    for(i = 0; i <= n; i++) s2 += pow(-1, i) * pow(x, i);
    for(i = 0; i <= n; i++) {
        double gt = 1;
        for(int j = 2; j <= i; j++) gt *= j;
        s3 += pow(x, i)/gt;
    }
    printf("%lf\n%lf\n%lf", s1, s2, s3);
    return 0;
}