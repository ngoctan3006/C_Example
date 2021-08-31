#include <stdio.h>
#include <math.h>

double calculate(double x) {
    if(x == 0) return 7;
    else if(x < 0) return (cos(4)*5*x*x + 5*sin(x*x*x-1));
    else return log2(x) + sqrt(x*x+5);
}

int main() {
    int n, i, count = 0;
    double x[200], y[200], z[200], sum = 0;
    do{
        scanf("%d", &n);
    } while(n < 1 || n > 20);
    x[0] = -1.5;
    for(i = -1; i <= 100; i++) x[i+2] = i;
    for(i = 0; i <= 103; i++) y[i] = calculate(x[i]);
    for(i = 0; i <= 103; i++)
        if(y[i] > n) {
            z[count++] = y[i];
            sum += y[i];
        }
    printf("%lf\n", sum);
    for(i = 0; i < count; i++) printf("%lf ", z[i]);
    return 0;
}