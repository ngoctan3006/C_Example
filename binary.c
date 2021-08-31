#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    int d = 0x80;
    for(int i = 0; i < 8; i++) {
        printf("%d", a&d ? 1:0);
        d >>= 1;
    }
    return 0;
}