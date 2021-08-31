#include <stdio.h>

int main() {
    int inputA, inputB, sum, start, destination;
    int check = 1;
    printf("SMART STRATEGY\n");
    printf("start: ");
    scanf("%d", &start);
    printf("destination: ");
    scanf("%d", &destination);
    sum = start;
    while(sum < destination) {
        printf("P1. Choose a number: ");
        do {
            scanf("%d", &inputA);
            if(inputA > 5) {
                printf("    <invalid - greater than 5>\n    Choose a number: ");
                check = 0;
                continue;
            }
            if(inputA < 1) {
                printf("    <invalid - must be a positive number>\n    Choose a number: ");
                check = 0;
                continue;
            }
            check = 1;
            sum += inputA;
            printf("    Now the value is %d\n", sum);
            if(sum >= destination) {
                printf("P1 has won the game! Congratulation\n");
                return 0;
            }
        } while(check != 1);
        printf("P2. Choose a number: ");
        do {
            scanf("%d", &inputB);
            if(inputB > 5) {
                printf("    <invalid - greater than 5>\n    Choose a number: ");
                check = 0;
                continue;
            }
            if(inputB < 1) {
                printf("    <invalid - must be a positive number>\n    Choose a number: ");
                check = 0;
                continue;
            }
            if((inputA-inputB)%2 == 0) {
                if(inputA%2) printf("    <invalid - must be even>\n    Choose a number: ");
                else printf("    <invalid - must be odd>\n    Choose a number: ");
                check = 0;
                continue;
            }
            check = 1;
            sum += inputB;
            printf("    Now the value is %d\n", sum);
            if(sum >= destination) {
                printf("P2 has won the game! Congratulation\n");
                return 0;
            }
        } while(check != 1);
    }
}