#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "linked_list.h"


Student initial_data[] = {
    { "AnhPT54", 1, 6 },
    { "BachTV", 2, 6 },
    { "BangTX", 3, 8 },
    { "BaoVQ5", 4, 7 },
    { "ChienND8", 5, 7 },
    { "DatNT162", 6, 10 },
    { "DuongNT62", 7, 8 },
    { "HanhNTH8", 8, 5 },
    { "HoaLK3", 9, 7 },
    { "HoangTHM", 10, 9 },
    { "HungDD8", 11, 6 },
    { "HuongPTT12", 12, 8 },
    { "HuongTT20", 13, 10 },
    { "LongNH58", 14, 7 },
    { "MinhBQ4", 15, },
    { "MinhPC9", 16, 7 },
    { "PhanDD", 17, 9 },
    { "PhuongNQT", 18, 9 },
    { "QuangTM12", 19, 8 },
    { "QuangTM13", 20, 10 },
    { "QuyenNT27", 21, 9 },
    { "QuyetCV1", 22, 9 },
    { "ThachHS", 23, 10 },
    { "ThangNC23", 24, 10 },
    { "TuanND53", 25, 5 },
    { "TienTA3", 26, 9 },
    { "TienTA3", 27, 8 },
    { "ThoPN", 28, 10 },
    { "TuND17", 29, 8 },
    { "TungBT14", 30, 9 },
    { "TungVT11", 31, 6 }
};

Student *createNode(uint8_t *name, uint16_t ID, uint8_t score) {
    Student *node = (Student*) malloc(sizeof(Student));
    strcpy(node->name, name);
    node->ID = ID;
    node->score = score;
    node->next = NULL;

    return node;
}

Student *addTail(Student *head, uint8_t *name, uint16_t ID, uint8_t score) {
    Student *node = createNode(name, ID, score);

    if(head == NULL) {
        head = node;
    }
    else {
        // node->next = head;
        Student *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }

    return head;
}

Student *addHead(Student *head, uint8_t *name, uint16_t ID, uint8_t score) {
    Student *node = createNode(name, ID, score);

    if(head == NULL) {
        /* Do nothing */
    }
    else {
        node->next = head;
    }

    return node;
}

Student *addByPos(Student *head, uint8_t *name, uint16_t ID, uint8_t score) {
    uint8_t pos;
    uint8_t count = 1;

    printf("\n\t\t  Enter position you want to add: ");
    do {
        scanf("%d", &pos);
        if(pos < 1) {
            printf("\t\t  [ ERROR ] Position must be greater than or equal to 1!\n");
            printf("\t\t  Enter again: ");
        }
    } while(pos < 1);

    if(pos == 1) {
        head = addHead(head, name, ID, score);
    }
    else {
        Student *temp = head;
        while((temp->next != NULL) && (count < (pos - 1))) {
            temp = temp->next;
            count++;
        }

        Student *node = createNode(name, ID, score);
        if(temp->next == NULL) {
            temp->next = node;
            printf("\t\t  [WARNING] The position you chose is too big!\n");
            printf("\t\t  This student will be added to the end of the list.\n");
        }
        else {
            node->next = temp->next;
            temp->next = node;
        }
    }

    return head;
}

Student *findID(Student *head, uint16_t ID) {
    Student *temp = head;
    while((temp != NULL) && (temp->ID != ID)) {
        temp = temp->next;
    }
    return temp;
}

Student *del(Student *head, uint16_t ID) {
    Student *temp = head;
    Student *del;

    if(head->ID == ID) {
        head = head->next;
    }
    else {
        while(temp->next->next != NULL && temp->next->ID != ID) {
            temp = temp->next;
        }
        del = temp->next;
        temp->next = temp->next->next;
        free(del);
    }
    return head;
}

void display(Student *head) {
    Student *temp = head;

    printf("\t\t+------+---------------------------+-------+\n");
    printf("\t\t| %-5s| %-25s | %-5s |\n", "ID", "Student's name", "Score");
    printf("\t\t+------+---------------------------+-------+\n");
    while (temp != NULL) {
        printf("\t\t| %-5d| %-25s | %-5d |\n", temp->ID, temp->name, temp->score);
        temp = temp->next;
    }
    printf("\t\t+------+---------------------------+-------+\n\n");
}

void showMenu(void) {
    printf("\t============================================================\n\n");
    printf("\t\t+------------------------------------------+\n");
    printf("\t\t|        Student management program        |\n");
    printf("\t\t+---+--------------------------------------+\n");
    printf("\t\t| 1 | Add student in the head of list      |\n");
    printf("\t\t| 2 | Add student in the tail of list      |\n");
    printf("\t\t| 3 | Add student by position              |\n");
    printf("\t\t| 4 | Find student by ID                   |\n");
    printf("\t\t| 5 | Delete student by ID                 |\n");
    printf("\t\t| 6 | Exit                                 |\n");
    printf("\t\t+---+--------------------------------------+\n\n");
}

Student *init(void) {
    uint8_t index = 0;
    Student *head = NULL;

    for(; index < INIT_NUM; index++) {
        head = addTail(head, initial_data[index].name, initial_data[index].ID, initial_data[index].score);
    }

    return head;
}

uint16_t readID(Student *head) {
    uint16_t ID;
    Student *isExist;

    printf("\n\t\t  Enter student's ID: ");
    do {
        do {
            scanf("%d", &ID);
            if((ID < 0) || (ID > 999)) {
                printf("\t\t  [ ERROR ] ID must be between 0 and 999!\n\t\t  Enter again: ");
            }
            else {
                /* Do nothing */
            }
        } while(( ID < 0) || ( ID > 999));

        isExist = findID(head, ID);
        if(isExist) {
            printf("\t\t  [ ERROR ] ID %d is already exists!\n\t\t  Enter again: ", ID);
        }
        else {
            /* Do nothing */
        }
    } while(isExist);

    return ID;
}

uint8_t readScore(void) {
    static uint8_t score;

    printf("\t\t  Enter student's score: ");
    do {
        scanf("%d", &score);
        if((score < 0) || (score > 10)) {
            printf("\t\t  [ ERROR ] Score must be between 0 and 10!\n\t\t  Enter again: ");
        }
        else {
            /* Do nothing */
        }
    } while(( score < 0) || ( score > 10));

    return score;
}

void freeList(Student *head) {
    Student *toFree = head;

    while(toFree != NULL) {
        head = head->next;
        free(toFree);
        toFree = head;
    }
}
