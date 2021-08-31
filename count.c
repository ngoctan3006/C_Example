#include <stdio.h>

int main() {
    int a[100], b, count = 0, i, j, n, check;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++)
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
    for(i = 0; i < n; i++) {
        check = 0;
        for(j = i-1; j >= 0; j--)
            if(a[i] == a[j]) {
                check = 1;
                break;
            }
        if(check) continue;
        b = 1;
        for(j = i+1; j < n; j++)
            if(a[i] == a[j])
                b++;
        printf("%d - %d; ", a[i], b);
    }
    return 0;
}