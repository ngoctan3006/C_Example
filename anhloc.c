#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[10];
    char name[30];
    int birthday;
    char class[15];
    float point;
} Student;


Student* input(Student*, int);
void printList(Student*, int);
void sort(Student*, int);
void exch(Student*, int, int);
void printMax(Student*, int);
void printFile(Student*, int);
void clear();


int main() {
    Student *infor = NULL;
    int n;
    printf("Nhap vao so luong sinh vien: ");
    scanf("%d", &n);
    clear();
    infor = input(infor, n);
    printList(infor, n);
    sort(infor, n);
    printf("Danh sach sau khi sap xep:\n");
    printList(infor, n);
    printMax(infor, n);
    printFile(infor, n);
    return 0;
}

Student* input(Student* infor, int n) {
    infor = (Student*) malloc(n*sizeof(Student));
    for(int i = 0; i < n; i++) {
        printf("\nSinh vien thu %d:\n", i+1);
        printf("  Name: ");
        scanf("%[^\n]s", infor[i].name);
        clear();
        printf("  MSSV: ");
        scanf("%[^\n]s", infor[i].id);
        clear();
        printf("  Nam sinh: ");
        scanf("%d", &infor[i].birthday);
        clear();
        printf("  Lop: ");
        scanf("%[^\n]s", infor[i].class);
        clear();
        printf("  Diem tong ket: ");
        scanf("%f", &infor[i].point);
        clear();
    }
    printf("\nDa nhap thanh cong %d sinh vien\n\n", n);
    return infor;
}

void clear() {
    while(getchar() != '\n');
}

void printList(Student* infor, int n) {
    printf("STT %-10s%-30s%-10s%-15s%-s\n", "MSSV", "Ho Ten", "Nam sinh", "Lop", "Diem tong ket");
    for(int i = 0; i < n; i++) {
        printf("%2d. %-10s%-30s%-10d%-15s%-5.2f\n", i+1, infor[i].id, infor[i].name, infor[i].birthday, infor[i].class, infor[i].point);
    }
    printf("\n\n");
}

void exch(Student* arr, int i, int j) {
    Student temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sort(Student* infor, int n) {
    int check = 1;
    for(int i = 0; i < n-1; i++) {
        check = 1;
        for(int j = 0; j < n-i-1; j++) {
            if(infor[j].point > infor[j+1].point) {
                exch(infor, j, j+1);
                check = 0;
            }
        }
        if(check) break;
    }
}

void printMax(Student* infor, int n) {
    sort(infor, n);
    printf("Sinh vien co diem tong ket lon nhat: %-10s%-30s\n\n", infor[n-1].id, infor[n-1].name);
}

void printFile(Student* infor, int n) {
    FILE *f = fopen("thilai.dat", "wb");
    if(f == NULL) {
        printf("[!] Mo file khong thanh cong!\n");
        return;
    }
    for(int i = 0; i < n; i++)
        if(infor[i].point < 5)
            fwrite(&infor[i], sizeof(Student), 1, f);
    printf("Da ghi vao file thanh cong\n\n");
    fclose(f);
}