#include <stdio.h>

int abs(int x) {
    if(x < 0) return -x;
    return x;
}

int main() {
    int h = 5;
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j < 2*h; j++) {
            if(j > h-i && j < h+i) printf("%3d", i - abs(h-j));
            else printf("   ");
        }
        printf("\n");
    }
    return 0;
}