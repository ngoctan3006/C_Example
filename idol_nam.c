#include <stdio.h>
// 1
// int main() {
//     int n, arr[100], i, s, e, temp;
//     printf("Enter number of array: ");
//     scanf("%d", &n);
//     for (i = 0; i < n; i++) {
//         printf("Enter elements of array: ");
//         scanf("%d", &arr[i]);
//     }
//     s = 0, e = n-1;
//     for (i = 0; i < n; i++) {
//         if ((arr[i] % 2 == 0) && (arr[i] % 3 == 0)) {
//             temp = arr[i];
//             arr[i] = arr[s];
//         }
//     }
//     return 0;
// }

// 2
// int main() {
//     int n, arr[100], x, k, i, j;
//     printf("Enter n: ");
//     scanf("%d", &n);
//     for (i = 0; i < n; i++) {
//         printf("Enter elements of array: ");
//         scanf("%d", &arr[i]);
//     }
//     printf("Enter x: ");
//     scanf("%d", &x);
//     printf("Enter k: ");
//     scanf("%d", &k);
//     if (k < 0) k = 0;
//     if (k >= n) {
//         arr[n] = x;
//     } else {
//         for (j = n; j > k; j--) {
//             arr[j] = arr[j - 1];
//         }
//         arr[k] = x;
//     }
//     n++;
//     for (i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

// 3
// int main() {
//     int n, arr[100], x, i, j, temp;
//     printf("Enter n: ");
//     scanf("%d", &n);
//     for (i = 0; i < n; i++) {
//         printf("Enter elements of array: ");
//         scanf("%d", &arr[i]);
//     }
//     for (i = 0; i < n - 1; i++) {
//         for (j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j+1]) {
//                 temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
//     printf("Enter x: ");
//     scanf("%d", &x);
//     n++;
//     i = 0;
//     while (i < n-1 && arr[i] < x) i++;
//     for (j = n-1; j > i; j--) {
//         arr[j] = arr[j-1];
//     }
//     arr[i] = x;
//     for (i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

// 4
int main() {
    int n, arr[100], x, i, j, temp;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements of array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
        if (arr[i] % 5 != 0)
            printf("%d ", arr[i]);
    }
    return 0;
}
