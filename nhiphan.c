#include <stdio.h>
#include <string.h>

int  main() {
    int input, count = 0;
    char binary[100], res[125];
    scanf("%d", &input);
    while(input != 0) {
        if(input%2) binary[count++] = '1';
        else binary[count++] = '0';
        input /= 2;
    }
    binary[count] = '\0';
    int i, j = 0;
    for(i = count-1; i >= 0; i--) {
        res[j++] = binary[i];
        if(j % 5 == 0) res[j++] = ' ';
    }
    res[j] = '\0';
    printf("%s", res);
    return 0;
}