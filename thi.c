
// #include <stdio.h>
// int main() {
//     int N, arr[100005], temp;
//     scanf("%d", &N);
//     for (int i = 0; i < N; i++) {
//         scanf("%d", &arr[i]);
//     }
//     for(int i = 0; i < N-1; i++) {
//         for(int j = 0; j < N-i-1; j++) {
//             if(arr[j] > arr[j+1]) {
//                 temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
//     int check = 0;
//     int d = arr[1] - arr[0];
//     int i = 2;
//     while (i <= N - 1) {
//         if (arr[i] - arr[i - 1] == d) {
//             check = 1;
//             i++;
//         }
//         else {
//             check = 0;
//             break;
//         }
//     }
//     if (check) printf("%d", d);
//     else printf("%d", arr[N-1]);
//     return 0;
// }

// #include <stdio.h>
// int main() {
//     int n;
//     do {
//         scanf("%d", &n);
//     } while(n <= 5 || n > 20);
//     int a[50], sumMax = 0, count = 0;
//     for(int i = 0; i < n; i++) scanf("%d", &a[i]);
//     for(int i = 1; i < n-1; i++) {
//         if(a[i] > a[i+1] && a[i] < a[i-1]) {
//             sumMax += a[i];
//             count++;
//         }
//     }
//     printf("%d", sumMax/count);
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// int main() {
//     char s[101];
//     int cc = 0, cs = 0;
//     fgets(s, 101, stdin);
//     s[strlen(s)-1] = '\0';
//     int len = strlen(s);
//     for(int i = 0; i < len; i++) {
//         if(s[i] >= 'a' && s[i] <= 'z') cc++;
//         if(s[i] >= 'A' && s[i] <= 'Z') cc++;
//         if(s[i] >= '0' && s[i] <= '9') cs++;
//     }
//     if(cc == cs) printf("0");
//     else if(cc > cs) printf("1");
//     else printf("2");
//     return 0;
// }

// #include <stdio.h>
// int main() {
//     int n, a[12];
//     scanf("%d", &n);
//     if (n < 2) {
//         printf("0");
//         return 0;
//     }
//     for (int i = 0; i < n; i++)
//         scanf("%d", &a[i]);
//     int max = -100000;
//     for (int i = 0; i < n - 1; i++) {
//         if (a[i] * a[i + 1] > max)
//             max = a[i] * a[i + 1]; 
//     }
//     printf("%d", max);
//     return 0;
// }

// #include <stdio.h>
// #include <math.h>
// int main() {
//     double k, e, sum = 0;
//     scanf("%lf%lf", &k, &e);
//     if(k <= 0 || k > 2) {
//         printf("Error");
//         return 0;
//     }
//     if(e <= 0 || e >= 1) {
//         printf("Error");
//         return 0;
//     }
//     int n = 1;
//     double x = k-1;
//     while(pow(x, n)/n >= e) {
//         sum += pow(-1, n-1) * pow(x, n) / n;
//         n++;
//     }
//     printf("%.7lf\n%d", sum, n);
//     return 0;
// }

// #include <stdio.h>
// #include <math.h>
// int main() {
//     int n;
//     double x, sum = 1;
//     scanf("%d%lf", &n, &x);
//     if(n <= 0) printf("Error");
//     for(int i = 1; i <= n; i++)
//         sum += pow(x,i);
//     printf("%lf", sum);
//     return 0;
// }

// #include <stdio.h>
// int main() {
//     int n, num1 = 0, num2 = 1, mul = 1, temp = 0;
//     scanf("%d", &n);
//     if(n <= 0 || n >= 40000) printf("Error\nError");
//     do {
//         num1 = num1 + num2;
//         temp = num2;
//         num2 = num1;
//         num1 = temp;
//         if(num1 * num2 <= n) mul = num1 * num2;
//     } while(num2 <= n);
//     printf("%d\n%d", num1, mul);
//     return 0;
// }

// #include <stdio.h>
// int main() {
//     int n;
//     scanf("%d", &n);
//     if(n <= 0 || n > 100) printf("Error");
//     int a[n], c1 = 0, c2 = 1, c3 = 0;
//     for(int i = 0; i < n; i++) scanf("%d", &a[i]);
//     for(int i = 1; i < n; i++) {
//         if(a[i] == a[0]) c2++;
//         else if(a[i] < a[0]) c1++;
//         else c3++;
//     }
//     printf("%d %d %d", c1, c2, c3);
//     return 0;
// }

// #include <stdio.h>
// int main() {
//     int n, temp, i, j;
//     scanf("%d", &n);
//     if(n <= 0 || n >= 100) printf("Error");
//     int a[n], count = 1;
//     for(i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//     }
//     for(i = 0; i < n-1; i++) {
//         for(j = 0; j < n-1-i; j++) {
//             if(a[j] < a[j+1]) {
//                 temp = a[j];
//                 a[j] = a[j+1];
//                 a[j+1] = temp;
//             }
//         }
//     }
//     for(i = 1; i < n; i++) {
//         if(a[i] == a[i-1]) count++;
//         else {
//             printf("%d %d\n", a[i-1], count);
//             count = 1;
//         }
//     }
//     printf("%d %d\n", a[n-1], count);
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// int DX(char *s)
//  { 
//   int i=0 , j=strlen(s)-1; 
//   while (i <= strlen(s)/2)
//   { 
//    if (s[i] != s[j]) 
//    return 0; 
//     i++; 
//     j--; 
//   } 
//    return 1; 
// }
// int main() {
//     int n, i, j;
//     char s[1000][1000];
//     scanf("%d", &n);
//     getchar();
//     if(n <= 0 || n >= 100)
//         printf("Error");
//     for(i = 0; i < n; i++) {
//         scanf("%s", s[i]);
//     }
//     for(i = 0; i < n; i++) {
//         if(DX(s[i])) {
//             printf("%s ", s[i]);
//         }
//     }
//     return 0;
// }

// #include <stdio.h>
// int main() {
//     int F[50];
//     int n;
//     scanf("%d", &n);
//     if (n <= 2) {
//         printf("Error");
//         return 0;
//     }
//     int a[10000];
//     int sum = 0;
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//         sum += a[i];
//     }
//     double avg = 1.0 * sum / n;
//     for (int x = 0; x < n; x++) {
//         for (int y = 0; y < n; y++) {
//             if (a[x] < a[y]) {
//                 int tmp = a[x];
//                 a[x] = a[y];
//                 a[y] = tmp;
//             }
//         }
//     }
//     int check = 1;
//     int i = 0;
//     while (i < n - 2) {
//         if (a[i] + a[i + 1] == a[i + 2])
//             i++;
//         else {
//             check = 0;
//             break;
//         }
//     }
//     if (check) printf("Co %lf", avg);
//     else printf("Khong %lf", avg);
//     return 0;
// }

// #include <stdio.h>
// int main() {
//     int n, count = 0, sum = 0;
//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++) {
//         if(n%i == 0) {
//             count++;
//             if(i%3 == 0 && i%5 != 0) {
//                 sum += i;
//             }
//         }
//     }
//     printf("%d\n%d", count, sum);
//     return 0;
// }

#include <stdio.h>
int main() {
    int n, sum = 0, count = 0;
    do {
        scanf("%d", &n);
    } while (n <= 5 || n > 20);
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 1; i < n-1; i++) {
        if(a[i] > a[i-1] && a[i] < a[i+1]) {
            sum += a[i];
            count++;
        }
    }
    if(count == 0) printf("0\n0.000000");
    else printf("%d\n%f", sum, (float) sum / count);
    return 0;
}