#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int coef;
    int exp;
} elementtypel;

typedef struct Node {
    elementtypel term;
    struct Node* next;
} Node;

Node *root, *root1, *root2, *root3, *root4;

Node* creatNode(int, int);
Node* insert(Node*, int, int);
Node* pairRoot(int);
Node* space(Node*);
Node* reset(Node*);
void display(Node*);
void sort(Node*);
void add();
void multiply();

int main() {
    char cmd[30];
    int c, e, list;
    while(1) {
        scanf("%s", cmd);
        if(strcmp(cmd, "***") == 0) break;
        else if(strcmp(cmd, "insert") == 0) {
            scanf("%d%d%d", &list, &c, &e);
            if(list == 1) root1 = insert(root1, c, e);
            else if(list == 2) root2 = insert(root2, c, e);
        } else if(strcmp(cmd, "display") == 0) {
            scanf("%d", &list);
            root = pairRoot(list);
            display(root);
        } else if(strcmp(cmd, "sort") == 0) {
            scanf("%d", &list);
            if(list == 1) sort(root1);
            else if(list == 2) sort(root2);
            else if(list == 3) sort(root3);
            else if(list == 4) sort(root4);
        } else if(strcmp(cmd, "add") == 0) {
            add();
        } else if(strcmp(cmd, "multiply") == 0) {
            multiply();
        } else if(strcmp(cmd, "space") == 0) {
            scanf("%d", &list);
            root = pairRoot(list);
            space(root);
        } else if(strcmp(cmd, "reset") == 0) {
            scanf("%d", &list);
            if(list == 1) root1 = reset(root1);
            else if(list == 2) root2 = reset(root2);
            else if(list == 3) root3 = reset(root3);
            else if(list == 4) root4 = reset(root4);
        }
    }
    reset(root);
    reset(root1);
    reset(root2);
    reset(root3);
    reset(root4);
    return 0;
}

Node* creatNode(int c, int e) {
    Node* p = (Node*) malloc(sizeof(Node));
    p->term.coef = c;
    p->term.exp = e;
    p->next = NULL;
    return p;
}

Node* insert(Node* root, int c, int e) {
    Node* q = creatNode(c, e);
    if(root == NULL) return q;
    for(Node* p = root; p != NULL; p = p-> next) {
        if(p->term.exp == e) {
            p->term.coef += c;
            return root;
        }
    }
    q->next = root;
    return q;
}

Node* pairRoot(int list) {
    if(list == 1) return root1;
    if(list == 2) return root2;
    if(list == 3) return root3;
    if(list == 4) return root4;
    return NULL;
}

void display(Node* root) {
    if(!root) return;
    for(Node* p = root; p != NULL; p = p->next) {
        printf("%d %d ", p->term.coef, p->term.exp);
    }
    printf("\n");
}

void sort(Node* root) {
    for(Node* p = root; p->next != NULL; p = p->next) {
        for(Node* q = p->next; q != NULL; q = q->next) {
            if(p->term.exp < q->term.exp) {
                elementtypel temp = p->term;
                p->term = q->term;
                q->term = temp;
            }
        }
    }
}

void add() {
    for(Node* p = root1; p != NULL; p = p->next)
        root3 = insert(root3, p->term.coef, p->term.exp);
    for(Node* p = root2; p != NULL; p = p->next)
        root3 = insert(root3, p->term.coef, p->term.exp);
    sort(root3);
    display(root3);
    root3 = reset(root3);
}

void multiply() {
    for(Node* p = root1; p != NULL; p = p->next)
        for(Node* q = root2; q != NULL; q = q->next)
            root4 = insert(root4, p->term.coef * q->term.coef, p->term.exp +  q->term.exp);
    sort(root4);
    display(root4);
    root4 = reset(root4);
}

Node* space(Node* root) {
    int count = 0;
    for(Node* p = root; p != NULL; p = p->next) {
        count++;
    }
    printf("%d\n", count*10);
}

Node* reset(Node* root) {
    Node* temp = root;
    while(temp != NULL) {
        root = root->next;
        free(temp);
        temp = root;
    }
    return NULL;
}