#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree-phonebook.h"

tree inputData(tree t);

void finding(tree t);

int main()
{
    FILE *fin;
    tree treePB = createNullTree();
    fin = fopen("data_week3.txt", "r+");
    if(fin == NULL)
    printf("\nCan't open file.");
    
    int running = 1;
  int selection;

  //initialize();

  while (running)
  {
    printf("\n--------------\n1. Read data\n");
    printf("2. Input data\n");
    printf("3. Find a phone by email.\n");
    printf("4. Increasing order printing.\n");
    
    printf("Choose an option:");
    scanf(" %d", &selection);
    switch (selection)
    {
    case 1:
      treePB = readInput(fin);
    printf("\n%s",treeToString(treePB));

      break;
      
    case 2:
      treePB = inputData(treePB);
      break;
    case 3:
      finding(treePB);
      break;
    case 4:
      inorderPrint(treePB);
      break;
    
     default:
      running = 0;
      break;
    }
  }

}

tree inputData(tree t) {
    element_t tempphone;
    char str_buffer[100];
    printf("\n-------------------***------------------");
    printf("\nName: ");
    scanf(" %[^\n]s", tempphone.name);
    printf("\nPhone: ");
    scanf(" %[^\n]s", tempphone.phone);
    printf("\nEmail: ");
    scanf(" %[^\n]s", tempphone.email);
    t = insertBST(t, tempphone);
    return t;
}

void finding(tree t)
{
    char strbuffer[41];
    printf("\nInput email to search: ");
    scanf("%s", strbuffer);
    tree retval = searchBST(t, strbuffer);
    if(retval != NULL)
    printf("\nFound: %s - %s - %s", retval->data.email, retval->data.name, retval->data.phone);
    else
    printf("\nNot found.");

}


