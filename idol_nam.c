// #include <stdio.h>
// int main() {
//     int n;
//     double x;
//     scanf("%d%lf", &n, &x);
//     if(n < 1 || x < 0) {
//         printf("Error\n");
//     } else {
//         double res = 1.0;
//         int m = 1;
//         double temp = x;
//         for(int i = 1; i <= n; i++) {
//             m *= -1;
//             res += m * x;
//             x *= temp;
//         }
//         printf("%.4lf\n", res);
//     }
//     return 0;
// }

#include <stdio.h>
int main() {
    int n;
    double x;
    scanf("%d%lf", &n, &x);
    if(n < 1 || x < 0) {
        printf("Error\n");
    } else {
        double res = 1.0;
        int gt = 1;
        double temp = x;
        for(int i = 1; i <= n; i++) {
            gt *= i;
            res += x / gt;
            x *= temp;
        }
        printf("%.4lf\n", res);
    }
    return 0;
}
