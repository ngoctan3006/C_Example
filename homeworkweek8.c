#include <stdio.h>
#include <stdlib.h>
int main(){
    int n1, n2, sum, destination, count1 = 0, count2 = 0;
    printf("SMART STRATEGY. \n");
    do{
        printf("Start:");
        scanf("%d", &sum);
    }while(sum<0);
    do{
        printf("Destination:");
        scanf("%d", &destination);
    }while(sum >= destination);
    do
    {
        printf("Player 1. Choose a number:");
        scanf("%d", &n1);
        while (n1<1 || n1>5)
        {
            if (n1 <1)  printf("<invalid - smaller than 1> \n");
            if (n1 >5)  printf("<invalid - greater than 5> \n");
            printf("Choose a number:");
            scanf("%d", &n1);
        }
        sum += n1;
        count1++;
        printf("Now the valid is %d \n", sum);
        if(sum >= destination) break;
        printf("Player 2. Choose a number:");
        scanf("%d", &n2);
        while (n2<1 || n2>5 || abs(n2 - n1)%2==0)
        {
            if (n2<1)  {printf("<invalid - smaller than 1> \n");}
            if (n2>5)  {printf("<invalid - greater than 5>\n");}
            if(n1%2==1)  {printf("<invalid - must be even>\n");}
            if (n1%2==0) {printf("<invalid - must be odd>\n");}
            printf("Choose a number:");
            scanf("%d", &n2);                            
        }
        sum += n2;
        count2++;
        printf("Now the valid is: %d \n", sum);      
    } while (sum < destination);
    if(count1> count2){
        printf("Player1 has won the game. Congratulatin! \n");
    }
    else
    {
        printf("Player2 has won the game. Congratulation! \n");
    }   
    return 0;
}