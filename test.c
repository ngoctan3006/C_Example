#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double x;
    double y;
    char name[51];
} LOC;

typedef struct aPlace {
    int hour, min;
    char locName[255];
    struct aPlace *next;
} PLACE;

void listF1Covid(LOC *listLoc, int n, double x, double y, double d);
int needMedicalReport(PLACE *visitedPlace, char *reportLocName, int reportHour, int reportMin);

int main() {
    return 0;
}

void listF1Covid(LOC *listLoc, int n, double x1, double y1, double d) {
    for (int i = 0; i <= n - 1; i++) {
        double dis = sqrt((listLoc[i].x - x1) * (listLoc[i].x - x1) + (listLoc[i].y - y1) * (listLoc[i].y - y1));
        if (dis <= d) {
            printf("%s\n", listLoc[i].name);
        }
    }
}

int needMedicalReport(PLACE *visitedPlace, char *reportLocName, int reportHour, int reportMin) {
    PLACE *temp = visitedPlace;
    while (temp != NULL) {
        if (strcmp(temp->locName, reportLocName) == 0) {
            if (((temp->hour == reportHour) && (temp->min >= reportMin)) || (temp->hour > reportHour))
                return 1;
        }
        temp = temp->next;
    }
    return 0;
}
