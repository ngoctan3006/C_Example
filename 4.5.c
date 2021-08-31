#include <stdio.h>
#include <math.h>

int  main() {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if(a == 0) {
        if(b == 0) {
            if(c == 0) printf("Phuong trinh vo so nghiem");
            else printf("Phuong trinh vo nghiem");
        }
        else printf("%lf", -c/b);
    }
    else {
        double delta = b*b - 4*a*c;
        if(delta == 0) printf("%lf", -b/(2*a));
        else if(delta > 0) {
            printf("%lf\n", (-b+sqrt(delta))/(2*a));
            printf("%lf", (-b-sqrt(delta))/(2*a));
        }
        else {
            delta = -delta;
            printf("%lf + %lfi\n", -b/(2*a), sqrt(delta)/(2*a));
            printf("%lf - %lfi\n", -b/(2*a), sqrt(delta)/(2*a));
        }
    }
    return 0;
}