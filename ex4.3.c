#include <stdio.h>
#include <math.h>

long long factorial(int n) {
    if(n == 0 || n == 1) return 1;
    else return n*factorial(n-1);
}

double s1(double x, int n) {
    double sum = 0;
    for(int i = 1; i <= n; i++) {
        sum = sqrt(x + sum);
    }
    return sum;
}

double s2(double x, int n) {
    double sum = 1;
    for(int i = 1; i <= n; i++) {
        sum += pow(x, i)/i;
    }
    return sum;
}

double s3(double x, int n) {
    double sum = 0;
    for(int i = 0; i <= n; i++) {
        sum += pow(x, i)/factorial(i);
    }
    return sum;
}

double s4(double x, int n) {
    double sum = 0;
    int s = 1;
    for(int i = 0; i <= n; i++) {
        sum += s*pow(x, i)/factorial(i);
        s *= -1;
    }
    return sum;
}

int main() {
    double x;
    int n;
    scanf("%lf%d", &x, &n);
    if(n < 1 || x < 0) printf("Error");
    else {
        printf("%.4lf\n", s1(x, n));
        printf("%.4lf\n", s2(x, n));
        printf("%.4lf\n", s3(x, n));
        printf("%.4lf\n", s4(x, n));
    }
    return 0;
}