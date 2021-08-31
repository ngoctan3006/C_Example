#include <stdio.h>
#include <math.h>

double Comp_H(float x, float y) {
    if(x < y-2) return (3*x*x - log(y));
    else if(y-2 <= x && x <= y+2) return ((x+y)/2 + 8);
    else return (y*y*y + 2*sin(x));
}

int main() {
    float a[17][2];
    int i, j;
    for(i = 5; i >= -11; i--) {
        a[-1*i+5][0] = (1-i)/2.0;
        a[-1*i+5][1] = i;
    }
    float b[17];
    for(i = 0; i < 17; i++)
        b[i] = Comp_H(a[i][0], a[i][1]);
    for(i = 0; i < 16; i++)
        for(j = 0; j < 16-i; j++)
            if(b[j] > b[j+1]) {
                float temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
    for(i = 0; i < 17; i++)
        printf("%f ", b[i]);
    return 0;
}