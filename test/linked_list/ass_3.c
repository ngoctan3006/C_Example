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

        printf("\t\t\t\tEnter your choice: ");
        do {
            scanf("%d", &choice);
            if(( choice < 1) ||( choice > 4)) {
                printf("\t\t\t\t  Choosen must be between 1 and 4!\n");
                printf("\t\t\t\t  Enter again: ");
            }
        } while(( choice < 1) ||( choice > 4));

        switch(choice) {
            case 1:
                ID = readID(head);
                printf("\t\t\t\t  Enter student's name: ");
                fflush(stdin);
                scanf("%[^\n]s", name);
                score = readScore();
                head = add(head, name, ID, score);
                printf("\n");
                break;
            case 2:
                printf("\t\t\t\t  Enter student's ID you want to find: ");
                scanf("%d", &ID);
                temp = findID(head, ID);
                if(temp) {
                    printf("Information of student with ID %d:\n", ID);
                    printf("Name: %s\nScore: %d\n\n", temp->name, temp->score);
                }
                else {
                    printf("Student with ID %d is not found!\n\n", ID);
                }
                break;
            case 3:
                printf("\t\t\t\t  Enter student's ID you want to delete: ");
                scanf("%d", &ID);
                if(findID(head, ID)) {
                    head = del(head, ID);
                    printf("Removed student with ID %d successfully!\n\n", ID);
                }
                else {
                    printf("ID %d is not exist!\n\n", ID);
                }
                break;
            case 4:
            default: break;
        }
    } while(choice != 4);

    return 0;
}
