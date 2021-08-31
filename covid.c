#include <stdio.h>
#include <string.h>

#define MAX 200

typedef struct {
    char country[30];
    long total;
    long new;
    long death;
} Statistic;

void clear();
int input(Statistic*, int);
void print(Statistic*, int);
void chuanHoa(Statistic*, int);
void sort(Statistic*, int);
void QGNC(Statistic*, int);

int main() {
    int choice, n = 0;
    Statistic covi_stat[MAX];
    do {
        printf("\n========= COVID ==========\n"
               "1. Nhap lieu\n"
               "2. Hien thi bang thong tin\n"
               "3. Chuan hoa ten quoc gia\n"
               "4. Sap xep\n"
               "5. Cac quoc gia nguy co\n"
               "6. Thoat\n"
               "========== END ===========\n");
        printf("Moi nhap vao lua chon: ");
        do {
            scanf("%d", &choice);
            clear();
            if(choice < 1 || choice > 6)
                printf("Lua chon khong hop le! Moi nhap lai: ");
        } while(choice < 1 || choice > 6);

        switch(choice) {
            case 1:
                n = input(covi_stat, n);
                break;
            case 2:
                print(covi_stat, n);
                break;
            case 3:
                chuanHoa(covi_stat, n);
                break;
            case 4:
                sort(covi_stat, n);
                break;
            case 5:
                QGNC(covi_stat, n);
                break;
            case 6:
                printf("Bye bye!! Hihi");
                return 0;
        }
    } while(choice != 6);
}

void clear() {
    while(getchar() != '\n');
}

int input(Statistic covi[], int n) {
    int k, i, j;
    printf("Nhap so luong cac quoc gia muon them: ");
    do {
        scanf("%d", &k);
        if(k <= 0 || k > MAX)
            printf("So luong ban nhap khong hop le! Moi nhap lai: ");
    } while(k <= 0 || k > MAX);
    for(i = n; i < n+k; i++) {
        printf("Quoc gia thu %d:\n", i-n+1);
        printf("  Ten quoc gia: ");
        scanf("%[^\n]s", covi[i].country);
        printf("  Tong so ca nhiem: ");
        clear();
        do {
            scanf("%ld", &covi[i].total);
            clear();
            if(covi[i].total < 0)
                printf("    So luong ban nhap khong hop le! Moi nhap lai: ");
        } while(covi[i].total < 0);
        printf("  So ca nhiem moi trong 24h qua: ");
        do {
            scanf("%ld", &covi[i].new);
            clear();
        } while(covi[i].new < 0 || covi[i].new > covi[i].total);
    }
}