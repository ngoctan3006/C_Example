#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000000

typedef struct NODE {
    char FoD[100];
    char name[100];
    int price;
    int timeCook;
    struct NODE *next;
}node;

node *menu = NULL;

node *createNode(char FoD[], char name[], int price, int timeCook ) {
    node *p = (node*) malloc(sizeof(node));
    strcpy(p->FoD, FoD);
    strcpy(p->name, name);
    p->price = price;
    p->timeCook = timeCook;
    p->next = NULL;
    return p;
}

node *add(node *menu,char FoD[], char name[], int price, int timeCook) {
    node *p = createNode(FoD, name, price, timeCook) ;
    if( menu == NULL) return p;
    else {
        node *cur = menu;
        while(cur->next != NULL) {
            if(cur->name == name) {
                return NULL;
            }
            cur = cur->next;
        }
        cur->next = p;
    }
    return menu;
}

int findPrice(node *menu, char name[]) {
    if(menu == NULL) return 0;
    else {
        node *cur = menu;
        while(cur != NULL) {
        if(strcmp(cur->name, name) == 0) {
            int a = cur->price;
            return a;
        }
        cur = cur->next;
        }
        return 0;
    }
}

void solve() {
    char cmd[100];
    int count = 0;
    while(1) {
        scanf("%s", cmd);
        if( strcmp(cmd, "***") == 0) {
            break;
        } else if( strcmp(cmd, "$ADD") == 0) {
            char FoD[100];
            scanf("%s", FoD);
            char name[100];
            scanf("%s", name);
            int gio = 0, phut = 0, price = 0, timeCook = 0;
            scanf("%d %d", &price, &timeCook);
            menu = add(menu, FoD, name, price, timeCook);
            count++;
            printf("%d", count);
        } else if( strcmp(cmd, "$PRICE") == 0) {
            char name[20];
            scanf("%s", name);
            printf("%d", findPrice(menu, name));
        } else if(strcmp(cmd, "$COUNT") == 0) {
            printf("%d", count);
        }
    }
}

int main() {
    solve();
    return 0;
}