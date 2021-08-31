#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 8
#define SIZE 4

typedef struct {
    char groupID;
    char teamName[SIZE][20];
    int points[SIZE];
    int goals[SIZE];
} Football;

void clear();
int insert(Football*, int);
void print(Football*, int);
void search(Football*, int);
void update(Football*, int);
void exch(Football*, int, int, int);
void sort(Football*, int);

int main() {
    Football group[MAX];
    int choice, n = 0;
    do {
        printf("\n========GIAI DAU U23 CHAU A=========\n"
               "1. Bo sung bang dau\n"
               "2. In thong tin cac bang dau\n"
               "3. Tim thong tin doi bong\n"
               "4. Cap nhat ket qua bang dau\n"
               "5. Sap xep thu tu trong moi bang dau\n"
               "6. Thoat chuong trinh\n"
               "================ END ===============\n");
        printf("Nhap vao lua chon: ");
        do {
            scanf("%d", &choice);
            clear();
            if(choice < 1 || choice > 6)
                printf("Lua chon khong hop le! Moi nhap lai: ");
        } while(choice < 1 || choice > 6);

        switch(choice) {
            case 1:
                n = insert(group, n);
                break;
            case 2:
                print(group, n);
                break;
            case 3:
                search(group, n);
                break;
            case 4:
                update(group, n);
                break;
            case 5:
                sort(group, n);
                break;
            case 6:
                printf("Bye bye!! Hihi\n");
                return 0;
        }
    } while(choice != 6);
}

void clear() {
    while(getchar() != '\n');
}

int insert(Football group[], int n) {
    int k;
    printf("Nhap so luong bang dau muon them: ");
    do {
        scanf("%d", &k);
        clear();
        if(k == 0) return n;
        if(k < 0) {
            printf("  [!]So ban nhap khong hop le!\n");
            printf("     Vui long nhap lai 1 so >= 0: ");
            continue;
        }
        if(k+n > MAX) {
            printf("  [!]Tong so luong bang dau phai nho hon %d!\n", MAX);
            printf("     Hien tai da co %d bang dau. Vui long nhap lai 1 so trong khoang tu 0 den %d: ", n, MAX-n);
            continue;
        }
    } while(k+n > MAX || k < 0);

    for(int i = n; i < k+n; i++) {
        int check = 1;
        printf("\n%d: ", i-n+1);
        printf("- Ten bang dau: ");
        do {
            scanf("%c", &group[i].groupID);
            clear();
            check = 1;
            if(group[i].groupID < 'A' || group[i].groupID > 'Z') {
                printf("     [!]Ten bang dau phai la 1 ky tu in hoa! Vui long nhap lai: ");
                check = 0;
                continue;
            }
            for(int j = 0; j < i; j++) {
                if(group[j].groupID == group[i].groupID) {
                    check = 0;
                    break;
                }
            }
            if(check == 0)
                printf("     [!]Ten da ton tai! Vui long nhap lai: ");
        } while(check == 0);

        for(int j = 0; j < SIZE; j++) {
            int x, y;
            printf("   - Nhap ten doi thu %d: ", j+1);
            do {
                scanf("%[^\n]s", group[i].teamName[j]);
                clear();
                check = 1;
                int len = strlen(group[i].teamName[j]);
                for(x = 0; x < len; x++) {
                    if(group[i].teamName[j][x] == ' ') {
                        check = 0;
                        printf("     [!]Ten doi khong duoc chua ky tu khoang trang! Vui long nhap lai: ");
                        break;
                    }
                }
                if(check == 0) continue;
                for(x = 0; x < i; x++) {
                    for(y = 0; y < SIZE; y++) {
                        if(strcmp(group[i].teamName[j], group[x].teamName[y]) == 0) {
                            check = 0;
                            break;
                        }
                    }
                    if(check == 0) {
                        break;
                    }
                }
                if(check == 0) {
                    printf("     [!]Doi %s da ton tai trong bang %c! Vui long nhap lai: ", group[i].teamName[j], group[x].groupID);
                    continue;
                }
                for(x = 0; x < j; x++) {
                    if(strcmp(group[i].teamName[j], group[i].teamName[x]) == 0) {
                        check = 0;
                        printf("     [!]Doi %s da ton tai trong bang dau nay! Vui long nhap lai: ", group[i].teamName[j]);
                        break;
                    }
                }
            } while(check == 0);

            printf("   - Nhap diem cua doi: ");
            do {
                scanf("%d", &group[i].points[j]);
                clear();
                if(group[i].points[j] < 0)
                    printf("     [!]Diem phai la so > 0! Vui long nhap lai: ");
            } while(group[i].points[j] < 0);

            printf("   - Nhap hieu so cua doi: ");
            scanf("%d", &group[i].goals[j]);
            clear();
            printf("\n");
        }
    }
    return (n+k);
}

void print(Football group[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Group %c\n", group[i].groupID);
        printf("%-25s%-10s%-10s\n", "Team", "Point", "Goal");
        for(int j = 0; j < SIZE; j++) {
            printf("%-25s%-10d%-10d\n", group[i].teamName[j], group[i].points[j], group[i].goals[j]);
        }
        printf("\n");
    }
}

void search(Football group[], int n) {
    char name[20];
    int i, j;
    printf("Nhap ten doi bong can tim: ");
    scanf("%[^\n]s", name);
    clear();
    for(i = 0; i < n; i++) {
        for(j = 0; j < SIZE; j++) {
            if(strcmp(name, group[i].teamName[j]) == 0) {
                printf("Group %c, %d Point, %d Goal\n", group[i].groupID, group[i].points[j], group[i].goals[j]);
                return;
            }
        }
    }
    printf("No result\n");
}

void update(Football group[], int n) {
    char name1[20], name2[20];
    int point1, point2, i, j, k, check = 0;
    printf("Nhap vao ket qua tran dau: ");
    scanf("%s%s%d%d", name1, name2, &point1, &point2);
    clear();
    for(i = 0; i < n; i++) {
        for(j = 0; j < SIZE; j++) {
            if(strcmp(name1, group[i].teamName[j]) == 0) {
                for(k = 0; k < SIZE; k++) {
                    if(strcmp(name2, group[i].teamName[k]) == 0) {
                        if(point1 > point2) {
                            group[i].points[j] += 3;
                        }
                        else if(point1 < point2) {
                            group[i].points[k] += 3;
                        }
                        else {
                            group[i].points[j] += 1;
                            group[i].points[k] += 1;
                        }
                        group[i].goals[j] += (point1-point2);
                        group[i].goals[k] += (point2-point1);
                        check = 1;
                        break;
                    }
                }
            }
            if(check) break;
        }
        if(check) break;
    }
    if(check) {
        printf("Group %c\n", group[i].groupID);
        printf("%-25s%-10s%-10s\n", "Team", "Point", "Goal");
        for(int j = 0; j < SIZE; j++) {
            printf("%-25s%-10d%-10d\n", group[i].teamName[j], group[i].points[j], group[i].goals[j]);
        }
    }
    else printf("Different group");
}

void exch(Football group[], int i, int j, int k) {
    int point = group[i].points[j];
    group[i].points[j] = group[i].points[k];
    group[i].points[k] = point;
    int goal = group[i].goals[j];
    group[i].goals[j] = group[i].goals[k];
    group[i].goals[k] = goal;
    char name[20];
    strcpy(name, group[i].teamName[j]);
    strcpy(group[i].teamName[j], group[i].teamName[k]);
    strcpy(group[i].teamName[k], name);
}

void sort(Football group[], int n) {
    int i, j, k;
    for(i = 0; i < n; i++) {
        for(j = 0; j < SIZE-1; j++) {
            for(k = 0; k < SIZE-j-1; k++) {
                if(strcmp(group[i].teamName[k], group[i].teamName[k+1]) > 0) {
                    exch(group, i, k, k+1);
                }
            }
        }
        for(j = 0; j < SIZE-1; j++) {
            for(k = 0; k < SIZE-j-1; k++) {
                if(group[i].goals[k] < group[i].goals[k+1]) {
                    exch(group, i, k, k+1);
                }
            }
        }
        for(j = 0; j < SIZE-1; j++) {
            for(k = 0; k < SIZE-j-1; k++) {
                if(group[i].points[k] < group[i].points[k+1]) {
                    exch(group, i, k, k+1);
                }
            }
        }
    }
    printf("Danh sach cac bang sau khi da sap xep:\n\n");
    print(group, n);
}