#include <stdio.h>
#include <string.h>
#include <ctype.h>

void upperCase(char *string);
void printCard(char *name, char *id, char *dob, char *class, char *graduation);

int main() {
    char name[40];
    char dob[20];
    char class[50];
    char id[10];
    char graduationYear[5];
    char graduation[10] = "30/07/";

    printf("Enter name: ");
    scanf("%[^\n]s", name);
    getchar();
    printf("Enter id: ");
    scanf("%[^\n]s", id);
    getchar();
    printf("Enter date of birth: ");
    scanf("%[^\n]s", dob);
    getchar();
    printf("Enter class: ");
    scanf("%[^\n]s", class);
    getchar();
    printf("Enter graduation year: ");
    scanf("%[^\n]s", graduationYear);
    getchar();
    upperCase(name);
    strcat(graduation, graduationYear);

    printCard(name, id, dob, class, graduation);
    return 0;
}

void upperCase(char *string) {
    int len = strlen(string);
    for(int i = 0; i < len; i++) {
        if(isalpha(string[i])) {
            string[i] = toupper(string[i]);
        }
    }
}

void printCard(char *name, char *id, char *dob, char *class, char *graduation) {
    printf("\n\n");
    printf("\t+--------------------------------------------------------------------------+\n");
    printf("\t| Lo |  %-45s %20s |\n", "TRUONG DAI HOC BACH KHOA HA NOI", "THE SINH VIEN ");
    printf("\t| go |  %-45s %20s |\n", "HANOI UNIVERSITY OF SCIENCE AND TECHNOLOGY", "Student ID Card");
    printf("\t|----+---------------------------------------------------------------------|\n");
    printf("\t|%74s|\n", "");
    printf("\t|    %-50s  +------------+    |\n", "Ho ten / Name:");
    printf("\t|        %-46s  |%12s|    |\n", name, "");
    printf("\t|%54s  |%12s|    |\n", "", "");
    printf("\t|    %-50s  |    %-8s|    |\n", "Ngay sinh / Date of Birth:", "Anh");
    printf("\t|        %-46s  |    %-8s|    |\n", dob, "The");
    printf("\t|%54s  |    %-8s|    |\n", "", "Sinh");
    printf("\t|    %-50s  |    %-8s|    |\n", class, "Vien");
    printf("\t|%54s  |%12s|    |\n", "", "");
    printf("\t|%54s  |%12s|    |\n", "", "");
    printf("\t|   %-51s  +------------+    |\n", "|| |||| ||| ||||| | ||");
    printf("\t|   %-71s|\n", "|| |||| ||| ||||| | ||");
    printf("\t|    %-51s  %-17s|\n", "Gia tri den / Valid Thru:", "MSSV / ID No.");
    printf("\t|     %-52s  %-15s|\n", graduation, id);
    printf("\t|%74s|\n", "");
    printf("\t+--------------------------------------------------------------------------+\n");
    printf("\n\n");
}