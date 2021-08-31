#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX 256
#define INIT_NUM 31

typedef struct student {
    uint8_t name[MAX];
    uint16_t ID;
    uint8_t score;
    struct student *next;
} Student;

Student *init(Student*);
Student *createNode(uint8_t*, uint16_t, uint8_t);
Student *add(Student*, uint8_t*, uint16_t, uint8_t);
Student *findID(Student*, uint16_t);
Student *del(Student*, uint16_t);
void showMenu();
void display(Student*);
uint16_t readID(Student*);
uint8_t readScore();

int main() {
    uint8_t name[MAX];
    uint16_t ID;
    uint8_t score;
    uint8_t choice;
    Student *head = init(NULL);
    Student *temp = NULL;
    display(head);
    showMenu();

    do {
        do {
            printf("Enter your choice: ");
            scanf("%d", &choice);
        } while(( choice < 1) ||( choice > 5));

        switch(choice) {
            case 1:
                ID = readID(head);
                printf("Enter student's name: ");
                fflush(stdin);
                scanf("%[^\n]s", name);
                score = readScore();

                head = add(head, name, ID, score);
                printf("\n");
                break;
            case 2:
                printf("Enter student's ID you want to find: ");
                scanf("%d", &ID);
                temp = findID(head, ID);
                if(temp) {
                    printf("Found student with ID %d:\n", ID);
                    printf("Name: %s\nScore: %d\n\n", temp->name, temp->score);
                }
                else {
                    printf("Student with ID %d is not found!\n\n", ID);
                }
                break;
            case 3:
                printf("Enter student's ID you want to delete: ");
                scanf("%d", &ID);
                if(findID(head, ID)) {
                    head = del(head, ID);
                    printf("Delete student with ID %d successfully!\n\n", ID);
                }
                else {
                    printf("ID %d is not exist!\n\n", ID);
                }
                break;
            case 4:
                display(head);
                break;
            case 5: break;
        }
    } while(choice != 5);

    return 0;
}


Student *createNode(uint8_t *name, uint16_t ID, uint8_t score) {
    Student *node = (Student*) malloc(sizeof(Student));
    strcpy(node->name, name);
    node->ID = ID;
    node->score = score;
    node->next = NULL;

    return node;
}

Student *add(Student *head, uint8_t *name, uint16_t ID, uint8_t score) {
    Student *node = createNode(name, ID, score);

    if(head == NULL) {
        head = node;
    }
    else {
        Student *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
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

    printf("%-5s%-25s%-5s\n", "ID", "Student's name", "Score");
    while (temp != NULL) {
        printf("%-5d%-25s%-5d\n", temp->ID, temp->name, temp->score);
        temp = temp->next;
    }
    printf("\n");
}

void showMenu() {
    printf("Student management program\n");
    printf("1. Add student\n");
    printf("2. Find student by id\n");
    printf("3. del student by id\n");
    printf("4. Show list\n");
    printf("5. Exit\n");
}

Student initial_data[INIT_NUM] = {
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

Student *init(Student *head) {
    uint8_t index = 0;

    for(; index < INIT_NUM; index++) {
        head = add(head, initial_data[index].name, initial_data[index].ID, initial_data[index].score);
    }

    return head;
}

uint16_t readID(Student *head) {
    uint16_t ID;
    Student *isExist;

    printf("Enter student's ID: ");
    do {
        do {
            scanf("%d", &ID);
            if((ID < 0) || (ID > 999)) {
                printf("ID must be between 0 and 999! Enter again: ");
            }
            else {
                /* Do nothing */
            }
        } while(( ID < 0) || ( ID > 999));

        isExist = findID(head, ID);
        if(isExist) {
            printf("ID %d is already exists! Enter again: ", ID);
        }
        else {
            /* Do nothing */
        }
    } while(isExist);

    return ID;
}

uint8_t readScore() {
    uint8_t score;

    printf("Enter student's score: ");
    do {
        scanf("%d", &score);
        if((score < 0) || (score > 10)) {
            printf("Score must be between 0 and 10! Enter again: ");
        }
        else {
            /* Do nothing */
        }
    } while(( score < 0) || ( score > 10));

    return score;
}
