#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    char id[10];
    float point;
} Student;

int printFile();
void readFile(Student *);
void exch(Student *, int, int);
void sort(Student *, int);
void outputArr(Student *, int);
int binarySearch(Student *, int, int, char *);
void clear();


int main() {
    int choice;
    int num, res;
    char id[10];
    Student data[100];
    do {
        printf("\n======= MENU =======\n"
               "1. Nhap thong tin SV\n"
               "2. Doc vao tu file\n"
               "3. Sap xep theo MSSV\n"
               "4. Tim theo MSSV\n"
               "5. Thoat chuong trinh\n"
               "=====================\n\n");
        printf("Moi nhap vao lua chon cua ban: ");
        do {
            scanf("%d", &choice);
            clear();
            if(choice < 1 || choice > 5)
                printf("Lua chon ban nhap khong hop le. Moi nhap lai: ");
        } while(choice < 1 || choice > 5);
        switch (choice) {
            case 1:
                num = printFile();
                break;
            case 2:
                readFile(data);
                break;
            case 3:
                sort(data, num);
                break;
            case 4:
                printf("Nhap MSSV ban muon tim: ");
                scanf("%[^\n]s", id);
                clear();
                res = binarySearch(data, 0, num-1, id);
                if(res == -1) printf("\nKhong tim thay MSSV ban da nhap!!\n\n");
                else {
                    printf("  Ho Ten: %s\n", data[res].name);
                    printf("  MSSV: %s\n", data[res].id);
                    printf("  Diem: %.2f\n", data[res].point);
                }
                break;
            case 5: return 0;
        }
    } while(choice != 5);
}


int printFile() {
    int count = 0;
    Student data;
    FILE *f = fopen("SV.txt", "w");
    if(f == NULL) {
        printf("\nMo file khong thanh cong!!\n");
        return -1;
    }
    while(1) {
        printf("\nSinh vien %d:\n", count+1);
        printf("  Nhap ten: ");
        scanf("%[^\n]s", data.name);
        clear();
        if(strcmp("###", data.name) == 0) break;
        printf("  Nhap MSSV: ");
        scanf("%[^\n]s", data.id);
        clear();
        printf("  Nhap diem: ");
        do {
            scanf("%f", &data.point);
            clear();
            if(data.point < 0 || data.point > 10)
                printf("  Diem ban nhap khong hop le. Moi nhap lai: ");
        } while(data.point < 0 || data.point > 10);
        fwrite(&data, sizeof(Student), 1, f);
        count++;
    }
    fclose(f);
    return count;
}

void readFile(Student data[]) {
    Student infor;
    int count = 0;
    FILE *f = fopen("SV.txt", "r");
    if(f == NULL) {
        printf("\nMo file khong thanh cong!!\n\n");
        return;
    }
    while(!feof(f)) {
        fread(&infor, sizeof(Student), 1, f);
        data[count++] = infor;
    }
    fclose(f);
    printf("\nDa doc file thanh cong!!\n\n");
}

void exch(Student *data, int i, int j) {
    Student temp;
    temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

void sort(Student *data, int num) {
    int check;
    for(int i = 0; i < num-1; i++) {
        check = 1;
        for(int j = 0; j < num-i-1; j++) {
            if(strcmp(data[j].id, data[j+1].id) > 0) {
                exch(data, j, j+1);
                check = 0;
            }
        }
        if(check) break;
    }
    outputArr(data, num);
}

void outputArr(Student *data, int num) {
    int count = 1;
    for(int i = 0; i < num; i++) {
        printf("\nSinh vien %d:\n", count++);
        printf("  Ho Ten: %s\n  MSSV: %s\n  Diem: %.2f\n\n", data[i].name, data[i].id, data[i].point);
    }
}

int binarySearch(Student *data, int l, int r, char *id) {
    if(l <= r) {
        int mid = (l+r)/2;
        if(strcmp(id, data[mid].id) == 0) return mid;
        else if(strcmp(id, data[mid].id) < 0)
            return binarySearch(data, l, mid-1, id);
        else return binarySearch(data, mid+1, r, id);
    }
    else return -1;
}

void clear() {
    while(getchar() != '\n');
}