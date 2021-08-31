#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char re_code[1000];
int DAY;
int num_pa;

typedef struct Node {
    char region_code[1000];
    int day;
    int number_patient;
    struct Node*next;
} Node;

Node* creatNode(char region[], int Day, int Number_patient) {
    Node* p = (Node*) malloc(sizeof(Node));
    strcpy(p->region_code, region);
    p->day = Day;
    p->number_patient = Number_patient;
    p->next = NULL;
    return p;
}

Node* Update(Node* h, char region[], int Day, int Number_patient) {
    if(h==NULL) return creatNode(region, Day, Number_patient);
    h->next= Update(h->next, region, Day, Number_patient);
    return h;
}
int count_total(Node* h) {
    int sum = 0;
    Node* p = h;
    while(p != NULL) {
        sum += p->number_patient;
        p = p->next;
    }
    return sum;
}

int Find_number_patients(Node* h,char region[],int Day) {
    int number = 0;
    Node* p = h;
    while(p!=NULL) {
        if(strcmp(p->region_code,region)==0 && p->day == Day)
            number = p->number_patient;
        p = p->next;
    }
    return number;
}

int count_number_patients_period(Node* h,int start,int end) {
    Node* p =h;
    int count = 0;
    for(p; p != NULL; p = p->next) {
        if(p->day >= start && p->day <= end)
            count += p->number_patient;
    }
    return count;
}

int count_number_patients_region(Node* h, char region[]) {
    Node* p = h;
    int count = 0;
    for(p; p != NULL; p = p->next){
        if(strcmp(p->region_code, region) == 0)
            count  += p->number_patient;
    }
    return count;
}

void Print(Node* h) {
    Node* p =h;
    while(p != NULL) {
        printf("%s ", p->region_code);
        printf("%d %d", p->day, p->number_patient);
        printf("\n");
        p = p->next;
    }
}

void free_list(Node* h) {
    while(h != NULL){
        Node *tmp = h;
        h = h->next;
        free(tmp);
    }
}
int main() {
    Node* h = NULL;
    char cmd[100];
    while(1) {
        scanf("%s", cmd);
        if(strcmp(cmd, "***") == 0) {
            free_list(h);
            break;
        }
        else if(strcmp(cmd, "$Update") == 0) {
            scanf("%s%d%d", re_code, &DAY, &num_pa);
            h = Update(h, re_code, DAY, num_pa);
        }
        else if(strcmp(cmd, "$CountTotalPatients") == 0){
            printf("%d\n", count_total(h));
        }
        else if(strcmp(cmd, "$FindNumberPatients") == 0){
            scanf("%s%d", re_code, &DAY);
            printf("%d\n", Find_number_patients(h, re_code, DAY));
        }
        else if(strcmp(cmd, "$CountNumberPatientsOfPeriod") == 0){
            int start, end;
            scanf("%d%d", &start, &end);
            printf("%d\n", count_number_patients_period(h, start, end));
        }
        else if(strcmp(cmd,"$CountNumberPatientsOfRegion") == 0){
            scanf("%s", re_code);
            printf("%d\n", count_number_patients_region(h, re_code));
        }
    }
    return 0;
}
