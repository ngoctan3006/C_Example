#include <stdio.h>
#include <math.h>

unsigned int largestPower(unsigned int n) {
    while(n >= 0) {
        int sq = sqrt(n);
        if(sq*sq == n) return n;
        n--;
    }
}

int main() {
    unsigned int n;
    scanf("%u", &n);
    printf("%u", largestPower(n));
    return 0;
}