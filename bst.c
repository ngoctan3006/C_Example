#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
} Node;
typedef Node* Tree;

Tree createNullTree();
Node* createNode(int);
int isEmptyTree(Tree);
int isLeaf(Tree);
int countNode(Tree);
void preOrder(Tree);
void inOrder(Tree);
void postOrder(Tree);
Tree leftChild(Tree);
Tree rightChild(Tree);


int main() {
    Tree tree = createNullTree();
    printf("%d", isEmptyTree(tree));
    return 0;
}


Tree createNullTree() {
    return NULL;
}

Node* createNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    if(node != NULL) {
        node->left = NULL;
        node->right = NULL;
        node->data = data;
    }
    return node;
}

int isEmptyTree(Tree tree) {
    return tree == NULL;
}

void preOrder(Tree tree) {
    if(tree != NULL) {
        printf("%d ", tree->data);
        postOrder(tree->left);
        postOrder(tree->right);
    }
}

void inOrder(Tree tree) {
    if(tree != NULL) {
        inOrder(tree->left);
        printf("%d ", tree->data);
        inOrder(tree->right);
    }
}

void postOrder(Tree tree) {
    if(tree != NULL) {
        postOrder(tree->left);
        postOrder(tree->right);
        printf("%d ", tree->data);
    }
}

Tree leftChild(Tree tree) {
    if(tree != NULL) return tree->left;
    return NULL;
}

Tree rightChild(Tree tree) {
    if(tree != NULL) return tree->right;
    return NULL;
}

int isLeaf(Tree tree) {
    if(tree != NULL) {
        return (leftChild(tree) == NULL && rightChild(tree) == NULL);
    }
    return -1;
}

int countNode(Tree tree) {
    if(isEmptyTree(tree)) return 0;
    else return 1 + countNode(tree->left) + countNode(tree->right);
}