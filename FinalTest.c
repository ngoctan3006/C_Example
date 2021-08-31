#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct {
    int coef;
    int exp;
}elementtypel;
typedef struct Node{
    elementtypel term;
    struct Node* next;
}Node;
Node* root, *root1, *root2, *root3, *root4;
int list;
Node* creatNode(int c, int e){
    Node* p = (Node*)malloc(sizeof(Node));
    p -> term . coef = c;
    p -> term . exp = e;
    p -> next = NULL;
    return p;
}
Node* removenode(Node* root, int c){
    if(root == NULL) return  NULL;
    if(root -> term . coef == c){
        Node* p = root;
        root = root -> next;
        free(p);
        return root;
    }
    root -> next = removenode(root  -> next, c);
    return root;
}
Node* insert(Node* root, int c, int e){
   Node* q = creatNode(c,e);
   if(root == NULL) return q;
   else if(c!= 0){
       for(Node* p = root; p != NULL; p = p-> next){
           if(p -> term . exp == e){
               p -> term . coef += c;
               if(p -> term . coef == 0) removenode(root, p -> term . coef);
               return root;
           }
       }
       q -> next = root;
       return q;
   }
   else if(c == 0) return root;
}
Node* pairroot(int list){
    if(list == 1) return root1;
    if(list == 2) return root2;
    if(list == 3) return root3;
    if(list == 4) return root4;
    return NULL;
}
void display(Node* root){
    if(root == NULL) printf(" ");
    for(Node* p = root; p != NULL; p = p -> next){
        printf("%d %d ", p -> term . coef, p -> term . exp);
    }
    printf("\n");
}
void sort(Node* root){
    for(Node* p = root; p != NULL; p = p -> next){
        for(Node* q = p -> next; q != NULL; q = q -> next){
            if(p -> term . exp < q -> term . exp){
                elementtypel tmp = p -> term;
                p -> term = q -> term;
                q -> term =  tmp;
            }
        }
    }
    display(root);
}
void add(){
    for(Node* p = root1; p != NULL; p = p -> next){
        root3 = insert(root3, p -> term . coef, p -> term .exp);
    }
    for(Node* p = root2; p != NULL; p = p -> next){
        root3 = insert(root3, p -> term . coef, p -> term .exp);
    }
    for(Node* p = root3; p != NULL; p = p -> next){
        if(p -> term . coef == 0){
            root3 = removenode(root3,p ->term .coef);
        }
    }
    sort(root3);
}
void multiply(){
    for(Node* p = root1; p != NULL; p = p-> next){
        for(Node* q = root2; q != NULL; q = q -> next){
            root4 = insert(root4,p -> term . coef * q -> term . coef, p -> term . exp +  q -> term . exp);
        }
    }
    for(Node* q = root4; q != NULL; q = q->next){
        if(q -> term . coef == 0){
            root4 = removenode(root4, q -> term . coef);
        }
    }
    sort(root4);
}
void space(Node* root){
    int count = 0;
    for(Node* p = root; p != NULL; p = p->next){
        count++;
    }
    printf("%d\n", count*10);
}
Node* reset(Node* root){
    Node* temp = root;
    while(temp != NULL) {
        root = root->next;
        free(temp);
        temp = root;
    }
    return NULL;
}
int main(){
    char cmd[30];
    while(1){
        scanf("%s", cmd);
        if(strcmp(cmd,"***") == 0) break;
        if(strcmp(cmd, "insert") == 0){
            int c,e;
            scanf("%d %d %d", &list, &c, &e);        
            if(list == 1) root1 = insert(root1,c,e);
            else if(list == 2) root2 = insert(root2,c,e);
            continue;   
        }
        if(strcmp(cmd,"display") == 0){
            scanf("%d", &list);
            root = pairroot(list);
            display(root);
            continue;
            
        }
        if(strcmp(cmd, "sort") == 0){
            scanf("%d", &list);
            if(list == 1) sort(root1);
            else if(list == 2) sort(root2);
            else if(list == 3) sort(root3);
            else if(list == 4) sort(root4);
            continue;
    
        }
        if(strcmp(cmd, "add") == 0){
            add();       
            continue;
        }
        if(strcmp(cmd, "multiply") == 0){
            multiply();
            continue;
        }
        if(strcmp(cmd, "space") == 0){
            scanf("%d", &list);
            root = pairroot(list);
            space(root);
            continue;
        }
        if(strcmp(cmd, "reset") == 0){
            scanf("%d", &list);
            root = pairroot(list);
            root = reset(root);
            continue;
        }
    }
    reset(root);
    reset(root1);
    reset(root2);
    reset(root3);
    reset(root4);
    return 0;
}