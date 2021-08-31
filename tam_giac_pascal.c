#include <stdio.h>

int C(int n, int k) {
    if(k == 0 || k == n) return 1;
    if(k == 1) return n;
    return C(n-1, k) + C(n-1, k-1);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i; j++) printf(" ");
        for(int j = 0; j <= i; j++) printf("%d ", C(i, j));
        printf("\n");
    }
    return 0;
}