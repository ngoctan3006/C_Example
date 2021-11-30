#include <stdio.h>

typedef struct {
    double x;
    double y;
} Point;

double sign(Point a, Point b, Point c) {
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}

int PointInTriangle(Point x, Point a, Point b, Point c) {
    int b1, b2, b3;
    b1 = sign(x, a, b) < 0;
    b2 = sign(x, b, c) < 0;
    b3 = sign(x, c, a) < 0;
    return ((b1 == b2) && (b2 == b3));
}

int main() {
    Point A, B, C, M;
    printf("Nhap toa do diem A:\n");
    printf("  x = ");
    scanf("%lf", &A.x);
    printf("  y = ");
    scanf("%lf", &A.y);
    printf("Nhap toa do diem B:\n");
    printf("  x = ");
    scanf("%lf", &B.x);
    printf("  y = ");
    scanf("%lf", &B.y);
    printf("Nhap toa do diem C:\n");
    printf("  x = ");
    scanf("%lf", &C.x);
    printf("  y = ");
    scanf("%lf", &C.y);
    printf("Nhap toa do diem M:\n");
    printf("  x = ");
    scanf("%lf", &M.x);
    printf("  y = ");
    scanf("%lf", &M.y);
    if(PointInTriangle(M, A, B, C)) {
        printf("Diem M nam trong tam giac\n");
    } else {
        printf("Diem M nam ngoai tam giac\n");
    }
    return 0;
}
