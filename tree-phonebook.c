#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree-phonebook.h"

tree createNullTree() {
  return (tree)NULL;
}

tree createTree(element_t x, tree l, tree r) {
  tree t = (tree)malloc(sizeof(struct TreeNode));
  t->data = x;
  t->left = l;
  t->right = r;
  //printf("\n...%s", t->data.email);
  return t;
}

tree createLeaf(element_t x) {
  return createTree(x, createNullTree(), createNullTree());
}

int isNullTree(tree t) {
  return (t == NULL);
}

int isLeaf(tree t) {
  return ((t != NULL) &&
	  (t->left == NULL) &&
	  (t->right == NULL)); 
}

int sizeOfTree(tree t) {
  if (isNullTree(t))
    return 0;
  else
    return (1 + sizeOfTree(t->left) + sizeOfTree(t->right));
}

// int sumOfTree(tree t) {
//   if (isNullTree(t))
//     return 0;
//   else
//     return (t->data + sumOfTree(t->left) + sumOfTree(t->right));
// }

char* treeToString(tree t) {
  char *result;
  char *left;
  char *right;
  
  if (isNullTree(t)) {
    result = (char*)malloc(4);
    strcpy(result, "Nil");
    return result;
  } else {
    left = treeToString(t->left);
    right = treeToString(t->right);
    
    result = (char*)malloc(40 + strlen(left) + strlen(right));
    sprintf(result, "node(%s,%s,%s)", t->data.email, left, right);
    free(left);
    free(right);
    return result;
  }
}

tree left(tree t) {
  if (isNullTree(t))
    return NULL;
  else return t->left;
}

tree right(tree t) {
  if (isNullTree(t))
    return NULL;
  else return t->right;
}

char* value(tree t) {
  // return the email
  if (isNullTree(t))
    return NULL;
  else return t->data.email;
}

struct TreeNode* leftMost(tree t) {
  struct TreeNode *n = t;
  
  if (isNullTree(t)) return NULL;
  while (!isNullTree(left(n)))
    n = left(n);
  return n;
}

struct TreeNode* rightMost(tree t) {
  struct TreeNode *n = t;
  
  if (isNullTree(t)) return NULL;
  while (!isNullTree(right(n)))
    n = right(n);
  return n;
}

tree addToLeftMost(tree t, element_t x) {
  tree n = leftMost(t);
  
  if (isNullTree(t))
    return createLeaf(x);
  else {
    n->left = createLeaf(x);
    return t;
  }
}

tree addToRightMost(tree t, element_t x) {
  tree n = rightMost(t);
  
  if (isNullTree(t))
    return createLeaf(x);
  else {
    n->right = createLeaf(x);
    return t;
  }
}

int height(tree t) {
  if(isNullTree(t))
  return 0;
  int max = height(t->left) > height(t->right);
  return max + 1;
  // TODO
}
int leavesCount(tree t) {
  // TODO
  if(isNullTree(t))
  return 0;
  if(isLeaf(t))
  return 1;
  return leavesCount(t->left) + leavesCount(t->right);
}
int innerNodeCount(tree t) {
  // TODO
  return sizeOfTree(t) - leavesCount(t);
}
int rightChildCount(tree t) {
  if(isNullTree(t) || isLeaf(t))
  return 0;
  if(t->right != NULL)
  return 1 + rightChildCount(t->left) +rightChildCount(t->left);
  else 
  return rightChildCount(t->left);
  // TODO
}

struct TreeNode *searchBST(tree t, char* x) {
  if (isNullTree(t))
    return NULL;
  
  if (strcmp(value(t), x) == 0)
    return t;
  else if (strcmp(value(t), x) < 0)
    return searchBST(right(t), x);
  else
    return searchBST(left(t), x);
}

tree insertBST(tree t, element_t x) {
  if (isNullTree(t))
    return createLeaf(x);

  if (strcmp(value(t), x.email) == 0)
    return t;
  else if (strcmp(value(t), x.email) > 0) {
    t->left = insertBST(t->left, x);
    return t;
  } else {
    t->right = insertBST(t->right, x);
    return t;
  }
}
// xoa nut goc va tra ve cay BST sau khi da xoa
tree removeRootBST(tree t) {
  tree p, tmp;
  
  if (isNullTree(t))
    return NULL;
  // Xoa nut la
  if (isLeaf(t)) {
    free(t);
    return NULL;
  }
  // Xoa nut co 1 con phai
  if (left(t) == NULL) {
    tmp = right(t);
    free(t);
    return tmp;
  }
  // Xoa nut co 1 con trai
  if (right(t) == NULL) {
    tmp = left(t);
    free(t);
    return tmp;
  }
  // Xoa nut co hai con
  p = t;
  tmp = right(t);
  while (left(tmp) != NULL) {
    p = tmp;
    tmp = left(tmp);
  }

  t->data = tmp->data;
  tmp = removeRootBST(tmp);
  if (p == t)
    p->right = tmp;
  else
    p->left = tmp;
  return t;
}

tree removeBST(tree t, element_t x) {
  tree p, tmp;
  
  if (isNullTree(t))
    return NULL;

  if (strcmp(value(t), x.email) == 0)
    return removeRootBST(t);

  p = NULL;
  tmp = t;
  while ((tmp != NULL) && (strcmp(tmp->data.email, x.email) != 0)) 
    if ((strcmp(value(tmp), x.email)) > 0) {
      p = tmp;
      tmp = tmp->left;
    } else {
      p = tmp;
      tmp = tmp->right;
    }

  if (tmp != NULL) {
    if (p->left == tmp) {
      p->left = removeRootBST(tmp);
    }
    else {
      p->right = removeRootBST(tmp);
    }
  }
  return t;
}

void freetree(tree t) {
  if( t != NULL)
  {
    freetree(t->right);
    freetree(t->left);
    free((void *) t);
  }
}

tree findMax(tree t) {
  tree n = t;
  if (isNullTree(t)) return NULL;
  while (!isNullTree(right(n)))
    n = right(n);
  return n;
}

tree findMin(tree t) {
  tree n = t;
  if (isNullTree(t)) return NULL;
  while (!isNullTree(left(n)))
    n = left(n);
  return n;
}

tree readInput(FILE *fin) {
  // Get the size of the list.
  tree t = createNullTree();
    element_t tempphone;
    char str_buffer[100];
    while (fgets(str_buffer, 99, fin) != NULL)
    {
        sscanf(str_buffer, "%[^,],%[^,],%[^,]", tempphone.name,
               tempphone.phone, tempphone.email);
        t = insertBST(t, tempphone);
        //printf("\nheight is %d", height(t));
    }
    fclose(fin);
    return t;
}

void inorderPrint(tree t) {
  if (t!=NULL)
	{
		inorderPrint(t->left);
		printf("%s\n",t->data.email);
		inorderPrint(t->right);
	}
}
void preorderPrint(tree t) {
if (t!=NULL)
	{
		printf("%s\n",t->data.email);
		preorderPrint(t->left);
		preorderPrint(t->right);
	}
}
void postorderPrint(tree t) {
  if (t!=NULL)
	{
		postorderPrint(t->left);
		postorderPrint(t->right);
		printf("%s\n",t->data.email);
	}
}
tree reverseTree(tree t) {
 if(t != NULL) {
   tree tmp;
   tmp = t->left;
   t->left = t->right;
   t->right = tmp;
   if(t->left != NULL) reverseTree(t->left);
   if(t->right != NULL) reverseTree(t->right);
 }
 return t;
}
