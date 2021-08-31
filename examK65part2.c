#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
typedef struct Res{
    char name[30];
    char description[500];
    float rating;
    char address[100];
}Res;

void clear(){
    while(getchar() != '\n');
}
int menu(){
    int n;
    printf("1: Nhap thong tin nha hang.\n");
    printf("2: In thong tin cac nha hang.\n");
    printf("3: Tim kiem theo ten.\n");
    printf("4: Tim kiem theo mo ta.\n");
    printf("5: Sap xep.\n");
    printf("6: Thoat.\n");
    printf("Nhap lua chon cua ban:");
    scanf("%d", &n);
    clear();
    return n;
}
Res Nhahang[MAX];
void Nhap_thong_tin(int n){
    for(int i = 1; i<=n; i++){
        printf("Nha hang %d:\n", i);
        printf("Name:");
        scanf("%[^\n]s", Nhahang[i].name);
        clear();
        printf("Description:");
        scanf("%[^\n]s", Nhahang[i].description);
        clear();
        printf("Rating:");
        scanf("%f", &Nhahang[i].rating);
        clear();
        printf("Address:");
        scanf("%[^\n]s", Nhahang[i].address);
        clear();
    }
}
void In_thong_tin(){
    int n;
    for(int i = 1; i<=n; i++){
        printf("Nha hang %d\n", i);
        printf("Name:%s\n",Nhahang[i].name);
        printf("Description:%s\n",Nhahang[i].description);
        printf("%.1f\n", Nhahang[i].rating);
        printf("Address:%s\n",Nhahang[i].address);
        printf("\n");
    }
}
void Tim_kiem_theo_ten(){
    int n;
    char indexname[30];
    for(int i = 1; i<=n ; i++){
        if(strcasecmp(indexname, Nhahang[i].name) == 0){
            printf("%s\t%s\t%.2f\t%s\n", Nhahang[i].name, Nhahang[i].description, Nhahang[i].rating, Nhahang[i].address);
        }
    }
}
int main(){
    char c;
    do{
        int option;
        do{
            int n;
            option = menu();
            switch(option){
                case 1:
                printf("Nhap so luong nha hang:");
                scanf("%d", &n);
                clear();
                Nhap_thong_tin(n);
                break;
                case 2:
                In_thong_tin();
                break;
                case 3:
                Tim_kiem_theo_ten();
                break;
                case 4:
                break;
                case 5:
                break;
                case 6:
                break;
                default:
                break;
            }
        }while(option != 6);
        printf("Ban co muon nhap them nhom moi khong co (y) hoac khong (n):");
        scanf("%c", &c);
        clear();
    }while(c == 'Y' || c == 'y');
    return 0;
}