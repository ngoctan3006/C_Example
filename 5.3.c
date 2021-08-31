#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    // scanf("%[^\n]s", s);
    getchar();
    fgets(s, 100, stdin);

    int i = 0, j, len;
    while(s[i] == ' ') i++;
    strcpy(&s[0], &s[i]);
    len = strlen(s);
    while(s[len-1] == ' ' || s[len-1] == '\n') len--;
    s[len] = '\0';
    
    for(i = 0; i < len-1; i++) {
        if(s[i] == ' ' && s[i+1] == ' ') {
            // strcpy(&s[i], &s[i+1]);
            for(j = i+1; j < len; j++)
                s[j] = s[j+1];
            i--; len--;
        }
    }
    for(i = 0; i < len; i++) {
        // s[i] = toupper(s[i]);
        if(s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
    }
    printf("%s:%d", s, len);
    return 0;
}