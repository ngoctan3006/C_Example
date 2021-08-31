#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[10];
    char name[30];
    double point;
} Student;

typedef struct Node {
    Student data;
    struct Node *next;
} Node;

Node *create(Student);
Node *insert(Node *, Node *);
Node *insertSort(Node *, Node *);
Node *input(Node *);
Node *searchID(Node *, char *);
int deleteID(Node *, char *);
void print(Node *);
void printFile(Node *, char *);
void readFile(Node *, char *);
void freeNode(Node *);
void clear();


int main() {
    Node *root = NULL;
    int choice;
    char id[10];
    do {
        printf("\n======= MENU =======\n"
               "1. Nhap thong tin SV\n"
               "2. Tim theo MSSV\n"
               "3. Xoa SV theo MSSV\n"
               "4. In tat ca SV\n"
               "5. Ghi ra file\n"
               "6. Doc vao tu file\n"
               "7. Thoat chuong trinh\n"
               "=====================\n\n");
        printf("Moi nhap vao lua chon cua ban: ");
        do {
            scanf("%d", &choice);
            clear();
            if(choice < 1 || choice > 7)
                printf("Lua chon ban nhap khong hop le. Moi nhap lai: ");
        } while(choice < 1 || choice > 7);

        switch (choice) {
            case 1:
                root = input(root);
                printf("\nDa them thanh cong!!\n");
                break;
            case 2:
                printf("\nNhap vao MSSV ban can tim: ");
                scanf("%[^\n]s", id);
                clear();
                Node *res = searchID(root, id);
                if(res != NULL)
                    printf("\nHo Ten: %s\nMSSV: %s\nDiem: %.2lf\n\n", res->data.name, res->data.id, res->data.point);
                else printf("\nKhong tim thay sinh vien co MSSV ban da nhap!\n\n");
                break;
            case 3:
                printf("\nNhap vao MSSV ban can xoa: ");
                scanf("%[^\n]s", id);
                clear();
                if(deleteID(root, id)) printf("\nDa xoa thanh cong!\n\n");
                else printf("\nKhong ton tai MSSV ban da nhap!\n\n");
                break;
            case 4:
                print(root);
                break;
            case 5:
                printFile(root, "sinhvien.dat");
                break;
            case 6:
                readFile(root, "sinhvien.dat");
                break;
            case 7:
                freeNode(root);
                return 0;
        }
    } while(choice != 7);
}


Node *input(Node *root) {
    Student infor;
    printf("\nNhap vao thong tin sinh vien: \n");
    printf("  Ho Ten: ");
    scanf("%[^\n]s", infor.name);
    clear();
    printf("  MSSV: ");
    scanf("%[^\n]s", infor.id);
    clear();
    printf("  Diem mon C Basic: ");
    scanf("%lf", &infor.point);
    clear();
    Node *new = create(infor);
    root = insertSort(root, new);
    return root;
}

int deleteID(Node *root, char *id) {
    Node *del = root;
    if(strcmp(root->data.id, id) == 0) {
        root = root->next;
        free(del);
        return 1;
    }
    Node *prev = root;
    while(del != NULL) {
        if(strcmp(del->data.id, id) == 0) {
            prev->next = del->next;
            free(del);
            return 1;
        }
        prev->next = del;
        del = del->next;
    }
    return 0;
}

void print(Node *root) {
    int count = 1;
    for(Node *cur = root; cur != NULL; cur = cur->next) {
        printf("\nSinh vien %d:\n", count++);
        printf("  Ho Ten: %s\n  MSSV: %s\n  Diem mon C Basic: %.2lf\n", cur->data.name, cur->data.id, cur->data.point);
    }
    printf("\n\n");
}

void printFile(Node *root, char *fileName) {
    FILE *f = fopen(fileName, "wb");
    if(f == NULL) {
        printf("\nKhong mo duoc file cua ban!\n\n");
        return;
    }
    for(Node *cur = root; cur != NULL; cur = cur->next) {
        fwrite(&(cur->data), sizeof(Student), 1, f);
    }
    printf("\nDa ghi file thanh cong!!\n\n");
    fclose(f);
}

void readFile(Node *root, char *fileName) {
    FILE *f = fopen(fileName, "rb");
    if(f == NULL) {
        printf("\nKhong mo duoc file cua ban!\n\n");
        return;
    }
    Student infor;
    while(!feof(f)) {
        fread(&infor, sizeof(Student), 1, f);
        Node *new = create(infor);
        root = insert(root, new);
    }
    printf("\nDa doc file thanh cong!!\n\n");
    fclose(f);
}

Node *searchID(Node *root, char *id) {
    Node *cur = root;
    for(; cur != NULL; cur = cur->next) {
        if(strcmp(cur->data.id, id) == 0) return cur;
    }
    return NULL;
}

Node *create(Student data) {
    Node *new = (Node *) malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

Node *insert(Node *root, Node *new) {
    new->next = root;
    return new;
}

Node *insertSort(Node *root, Node *new) {
    for(Node *cur = root; cur != NULL; cur = cur->next) {
        if(new->data.point >= cur->data.point) {
            new->next = cur->next;
            cur->next = new;
            return root;
        }
    }
}

void clear() {
    while(getchar() != '\n');
}

void freeNode(Node *root) {
    Node *to_free = root;
    while(to_free != NULL) {
        root = root->next;
        free(to_free);
        to_free = root;
    }
}