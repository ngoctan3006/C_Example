#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "linked_list.h"

int main() {
    static uint8_t name[MAX];
    static uint16_t ID;
    static uint8_t score;
    static int16_t choice;
    Student *head = init();
    Student *temp = NULL;

    do {
        display(head);
        showMenu();

        printf("\t\tEnter your choice: ");
        do {
            scanf("%d", &choice);
            if(( choice < 1) ||( choice > 6)) {
                printf("\n\t\t[ ERROR ] You are only allowed to choose from 1 to 6!\n");
                printf("\t\tEnter again: ");
            }
        } while(( choice < 1) ||( choice > 6));

        switch(choice) {
            case 1:
                ID = readID(head);
                printf("\t\t  Enter student's name: ");
                fflush(stdin);
                scanf("%[^\n]s", name);
                score = readScore();
                head = addHead(head, name, ID, score);
                printf("\n\t\t  Done!\n");
                printf("\t\t  Added student with ID %d successfully!\n", ID);
                printf("\t\t  Press Enter to continue...");
                fflush(stdin);
                while(getchar() != '\n');
                printf("\n");
                break;
            case 2:
                ID = readID(head);
                printf("\t\t  Enter student's name: ");
                fflush(stdin);
                scanf("%[^\n]s", name);
                score = readScore();
                head = addTail(head, name, ID, score);
                printf("\n\t\t  Done!\n");
                printf("\t\t  Added student with ID %d successfully!\n", ID);
                printf("\t\t  Press Enter to continue...");
                fflush(stdin);
                while(getchar() != '\n');
                printf("\n");
                break;
            case 3:
                ID = readID(head);
                printf("\t\t  Enter student's name: ");
                fflush(stdin);
                scanf("%[^\n]s", name);
                score = readScore();
                head = addByPos(head, name, ID, score);
                printf("\n\t\t  Done!\n");
                printf("\t\t  Added student with ID %d successfully!\n", ID);
                printf("\t\t  Press Enter to continue...");
                fflush(stdin);
                while(getchar() != '\n');
                printf("\n");
                break;
            case 4:
                printf("\n\t\t  Enter student's ID you want to find: ");
                scanf("%d", &ID);
                temp = findID(head, ID);
                if(temp) {
                    printf("\n\t\t  Success!\n\n");
                    printf("\t\t  +--------+---------------------------+\n");
                    printf("\t\t  | ID     | %-5d                     |\n", temp->ID);
                    printf("\t\t  | Name   | %-25s |\n", temp->name);
                    printf("\t\t  | Score  | %-5d                     |\n", temp->score);
                    printf("\t\t  +--------+---------------------------+\n\n");
                }
                else {
                    printf("\n\t\t  Student with ID %d is not found!\n\n", ID);
                }
                printf("\t\t  Press Enter to continue...");
                fflush(stdin);
                while(getchar() != '\n');
                break;
            case 5:
                printf("\n\t\t  Enter student's ID you want to delete: ");
                scanf("%d", &ID);
                if(findID(head, ID)) {
                    head = del(head, ID);
                    printf("\n\t\t  Done!\n");
                    printf("\t\t  Removed student with ID %d successfully!\n\n", ID);
                }
                else {
                    printf("\t\t  [ ERROR ] ID %d is not exist!\n\n", ID);
                }
                printf("\t\t  Press Enter to continue...");
                fflush(stdin);
                while(getchar() != '\n');
                break;
            case 6:
                freeList(head);
                break;
            default: break;
        }
    } while(choice != 6);

    return 0;
}
