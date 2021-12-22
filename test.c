#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    char name[51];
} LOC;

void listF1Covid(LOC *listLoc, int n, double x, double y, double d);

int main() {
    return 0;
}

void listF1Covid(LOC *listLoc, int n, double x1, double y1, double d) {
    for (int i = 0; i <= n - 1; i++) {
        double dis = sqrt((listLoc[i].x - x1) * (listLoc[i].x - x1) + (listLoc[i].y - y1) * (listLoc[i].y - y1));
        if (dis <= d) {
            printf("%s\n", listLoc[i].name);
        }
    }
}
