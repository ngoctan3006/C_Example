#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#define MAX 256
#define INIT_NUM 31


typedef struct student {
    uint8_t name[MAX];
    uint16_t ID;
    uint8_t score;
    struct student *next;
} Student;


Student *init(void);
Student *createNode(uint8_t*, uint16_t, uint8_t);
Student *add(Student*, uint8_t*, uint16_t, uint8_t);
Student *findID(Student*, uint16_t);
Student *del(Student*, uint16_t);
void showMenu(void);
void display(Student*);
uint16_t readID(Student*);
uint8_t readScore(void);

#endif /*_LINKED_LIST_H_*/
