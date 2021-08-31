#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ull unsigned long long
#define M 100000

typedef struct Node {
    ull k;
    struct Node* next;
}Node;

Node* f[M];

Node* creatNode(ull k) {
    Node* p = (Node*) malloc(sizeof(Node));
    p->k = k;
    p->next = NULL;
    return p;
}

Node* insert_last(Node* p , ull k) {
    if(p == NULL) return creatNode(k);
    p->next = insert_last(p->next, k);
    return p;
}

Node* find_list(Node* p, ull k) {
    for(Node* q = p; q != NULL; q = q->next) {
        if(q->k == k) return q;
    }
    return NULL;
}

int h(ull k, ull index) {
    if(k % index == 0) return index - 1;
    return k % index - 1;
}

int find(ull k, ull index) {
    int i = h(k, index);
    Node* q = find_list(f[i], k);
    if(q == NULL) return 0;
    else return 1;
}

void insert(ull k, ull index) {
    int i = h(k, index);
    f[i] = insert_last(f[i], k);
}

int count_customer_inline(Node* p) {
    int count = 0;
    Node* q = p;
    while(q != NULL) {
        count += 1;
        q = q->next;
    }
    return count;
}

void print_list(Node* p) {
    Node* q = p;
    while(q != NULL) {
        printf("%lld ", q->k);
        q = q->next;
    }
}

int main() {
    ull k = 1;
    ull index = 4;
    char cmd[100];
    while(1) {
        scanf("%s", cmd);
        if(strcmp(cmd, "***") == 0) {
            break;
        } else if(strcmp(cmd, "$Enter") == 0) {
            int i = h(k, index);
            insert(k, index);
            printf("%lld %d\n", k, i+1);
            k++;
        } else if(strcmp(cmd, "$CountNumberCustomerInLine") == 0) {
            int line;
            scanf("%d", &line);
            printf("%d\n", count_customer_inline(f[line-1]));
        } else if(strcmp(cmd, "$ListCustomerInLine") == 0) {
            int line;
            scanf("%d", &line);
            if(f[line-1] == NULL) printf("Error\n");
            print_list(f[line-1]);
            printf("\n");
        }
        // else if(strcmp(cmd, "$Checkout") == 0) {
        //     ull x;
        //     scanf("%lld", &x);
        //     int j = h(x, index);
        // }
        else if(strcmp(cmd, "$CountNumberCustomerInAllLines") == 0) {
            int count_all = 0;
            for(int i = 0;i<index;i++) {
                count_all += count_customer_inline(f[i]);
            }
            printf("%d\n",count_all);
        }
    }
    return 0;
}
