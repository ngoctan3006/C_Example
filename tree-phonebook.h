#ifndef _TREE_PHONEBOOK_H_
#define _TREE_PHONEBOOK_H_

struct phonebook {
  char name[40];
  char phone[15];
  char email[40];
};
typedef struct phonebook element_t;

struct TreeNode {
  element_t data;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode* tree;

tree createNullTree();
tree createLeaf(element_t x);
tree createTree(element_t x, tree l, tree r);

int isNullTree(tree t);
int isLeaf(tree t);

tree left(tree t);
tree right(tree t);
char* value(tree t);

int sizeOfTree(tree t);
//int sumOfTree(tree t);
char* treeToString(tree t);

struct TreeNode* leftMost(tree t);
struct TreeNode* rightMost(tree t);

tree addToLeftMost(tree t, element_t x);
tree addToRightMost(tree t, element_t x); 

tree insertBST(tree t, element_t x);
// xoa nut goc va tra ve cay BST sau khi da xoa
tree removeRootBST(tree t);
tree removeBST(tree, element_t x);
struct TreeNode *searchBST(tree t, char * x);
void treefree(tree t);
tree findMax(tree t);
tree findMin(tree t);
tree readInput(FILE *fin);
void inorderPrint(tree t);
void preorderPrint(tree t);
void postorderPrint(tree t);
tree reverseTree(tree t);

#endif
