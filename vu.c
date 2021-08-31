#include <stdio.h>
#include <string.h>

int main() {
    char t[1000], s[1000];
    gets(s);
    gets(t);
    int count[26] = {0};
    char *final = strcat(s, t);
    int len = strlen(final);
    for(int i = 0; i < len; i++)
        count[final[i]-'a']++;
    for(int i = 0; i < 26; i++)
        if(count[i] > 0) printf("%c", i+'a');
    printf("\n");
    for(int i = 0; i < 26; i++)
        if(count[i] > 0) printf("%d\n", count[i]);
    return 0;
}