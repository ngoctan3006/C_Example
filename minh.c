#include <stdio.h>
#include <stdlib.h>

void input() {
    FILE *f = fopen("my_score.txt", "w");
    if(f == NULL) {
        printf("Loi mo file!\n");
        return;
    }
    double gk, ck;
    for(int i = 0; i < 2; i++) {
        printf("Nhap diem gk va ck: ");
        scanf("%lf%lf", &gk, &ck);
        fprintf(f, "%lf %lf\n", gk, ck);
    }
    fclose(f);
}

void readFile() {
    FILE *f = fopen("my_score.txt", "r");
    if(f == NULL) {
        printf("Loi mo file!\n");
        return;
    }
    printf("%-10s%-10s%-10s\n", "GK", "CK", "Final Mark");
    double gk, ck, tk;
    for(int i = 0; i < 2; i++) {
        fscanf(f, "%lf%lf", &gk, &ck);
        tk = gk*0.3 + ck*0.7;
        printf("%-10.2lf%-10.2lf%-10.2lf\n", gk, ck, tk);
    }
    fclose(f);
}

int main() {
    input();
    readFile();
    return 0;
}