#include <stdio.h>
#include <string.h>

int count(char c) {
    char key[9][5] = {" ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for (int i = 0; i < 9; i++) {
        int len = strlen(key[i]);
        for (int j = 0; j < len; j++)
            if(c == key[i][j]) return j+1;
    }
    return 0;
}

int solve(char *s) {
    int len = strlen(s), res = 0;
    for (int i = 0; i < len; i++)
        res += count(s[i]);
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    while(getchar() != '\n');
    char input[n][1000];
    for(int i = 0; i < n; i++) {
        scanf("%[^\n]s", input[i]);
        while(getchar() != '\n');
    }
    printf("%d\n", n);
    for(int i = 0; i < n; i++)
        printf("%d\n", solve(input[i]));
    return 0;
}