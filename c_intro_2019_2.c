#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char name[20];
    float gk, ck, tk;
    char xl;
} DiemSV;

void printMenu();
int input(DiemSV[], int);
void show(DiemSV[], int);
void chechLech(DiemSV[], int);
void sort(DiemSV[], int);
char XL(float);
void printTitle();
void clear();
void swap(DiemSV[], int, int);

int main() {
    int choice, n = 0;
    DiemSV sv[MAX];

    do {
        printMenu();
        printf("Press 1, 2, 3, 4, 5 to choose: ");

        do {
            scanf("%d", &choice);
            clear();
            if(choice < 1 || choice > 5)
                printf("Lua chon khong hop le! Vui long nhap lai: ");
        } while(choice < 1 || choice > 5);

        switch(choice) {
            case 1:
                n = input(sv, n);
                break;
            case 2:
                show(sv, n);
                break;
            case 3:
                chechLech(sv, n);
                break;
            case 4:
                sort(sv, n);
                break;
            case 5:
                break;
        }
    } while(choice != 5);
    return 0;
}

void clear() {
    while(getchar() != '\n');
}

void printMenu() {
    printf("\nChuong Trinh Quan Ly Diem Mon Hoc\n");
    printf("1. Nhap Diem\n");
    printf("2. In Bang Diem\n");
    printf("3. Chenh Lech Diem\n");
    printf("4. Sap Xep\n");
    printf("5. Thoat Chuong Trinh\n\n");
}

int input(DiemSV sv[], int size) {
    int n;
    printf("\nNhap vao so luong sinh vien can them: ");
    do {
        scanf("%d", &n);
        clear();
        if(n <= 0)
            printf("So luong khong hop le! Vui long nhap lai: ");
    } while (n <= 0);

    for(int i = size; i < n+size; i++) {
        printf("\nThong tin sinh vien thu %d:\n", i + 1);
        printf("  Ten sinh vien: ");
        scanf("%[^\n]s", sv[i].name);
        clear();
        printf("  Diem GK: ");
        scanf("%f", &sv[i].gk);
        clear();
        printf("  Diem CK: ");
        scanf("%f", &sv[i].ck);
        clear();
        sv[i].tk = sv[i].gk*0.4 + sv[i].ck*0.6;
        if(sv[i].gk <= 3 || sv[i].ck <= 3)
            sv[i].xl = 'F';
        else sv[i].xl = XL(sv[i].tk);
    }
    return n+size;
}

char XL(float f) {
    if(f >= 8.5) return 'A';
    if(f >= 7) return 'B';
    if(f >= 5.5) return 'C';
    if(f >= 4) return 'D';
    return 'F';
}

void printTitle() {
    printf("%-25s%-10s%-10s%-10s%-10s\n", "Ten SV", "Diem QT", "Diem CK", "Diem TK", "Xep Loai");
}

void show(DiemSV sv[], int n) {
    printTitle();
    for(int i = 0; i < n; i++) {
        printf("%-25s%-10.2f%-10.2f%-10.2f%-10c\n", sv[i].name, sv[i].gk, sv[i].ck, sv[i].tk, sv[i].xl);
    }
}

void chechLech(DiemSV sv[], int n) {
    float L;
    printf("\nNhap vao L: ");
    do {
        scanf("%f", &L);
        clear();
        if(L < 2 || L > 5)
            printf("L phai nam trong khoang [2, 5]: ");
    } while (L < 2 || L > 5);
    printTitle();
    for(int i = 0; i < n; i++) {
        if(fabs(sv[i].gk - sv[i].ck) >= L)
            printf("%-25s%-10.2f%-10.2f%-10.2f%-10c\n", sv[i].name, sv[i].gk, sv[i].ck, sv[i].tk, sv[i].xl);
    }
}

void sort(DiemSV sv[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(strcmp(sv[j].name, sv[j+1].name) > 0) {
                swap(sv, j, j+1);
            }
        }
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(sv[j].tk < sv[j+1].tk) {
                swap(sv, j, j+1);
            }
        }
    }

    show(sv, n);
}

void swap(DiemSV sv[], int i, int j) {
    DiemSV temp = sv[i];
    sv[i] = sv[j];
    sv[j] = temp;
}