#include <stdio.h>
#include <string.h>

int main() {
    char s[100][1000];
    int n, i;
    scanf("%d", &n);
    getchar();
    for(i = 0; i < n; i++) {
        scanf("%[^\n]s", s[i]);
        getchar();
        int j = 0, len;
        while(s[i][j] == ' ') j++;
        strcpy(&s[i][0], &s[i][j]);
        len = strlen(s[i]);
        while(s[i][len-1] == ' ') len--;
        s[i][len] = '\0';
        for(j = 0; j < len; j++) {
            if(s[i][j] == ' ' && s[i][j+1] == ' ') {
                strcpy(&s[i][j], &s[i][j+1]);
                j--; len--;
            }
        }
        for(j = 0; j < len; j++)
            if(s[i][j] >= 'a' && s[i][j] <= 'z')
                s[i][j] -= 32;
    }
    for(i = 0; i < n; i++)
        printf("%s:%d\n", s[i], strlen(s[i]));
}