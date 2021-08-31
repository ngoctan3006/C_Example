#include <stdio.h>
#include <string.h>
#include <ctype.h>

void rmSpAtHead(char *);
void rmSpAtTail(char *);
void rmSpAtMid(char *);
void chuanHoa(char *);

int main() {
    char s[100];
    printf("Nhap vao xau cua ban: ");
    scanf("%[^\n]s", s);
    rmSpAtHead(s);
    rmSpAtTail(s);
    rmSpAtMid(s);
    chuanHoa(s);
    printf("Xau sau khi chuan hoa: %s\n", s);
    printf("Do dai: %d", (int) strlen(s));
    return 0;
}

void rmSpAtHead(char *s) {
    int c = 0, len = strlen(s);
    while(c < len && isspace(s[c])) c++;
    // for(int i = 0; i <= len-c; i++)
    //     s[i] = s[i+c];
    strcpy(&s[0], &s[c]);
}

void rmSpAtTail(char *s) {
    int len = strlen(s);
    while(len >= 0 && isspace(s[len-1])) len--;
    s[len] = '\0';
}

void rmSpAtMid(char *s) {
    int len = strlen(s);
    for(int i = 0; i < len-1; i++) {
        if(isspace(s[i]) && isspace(s[i+1])) {
            // for(int j = i; j < len; j++)
            //     s[j] = s[j+1];
            strcpy(&s[i], &s[i+1]);
            i--; len--;
        }
    }
}

void chuanHoa(char *s) {
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    }
    s[0] -= 32;
    for(int i = 0; i < len; i++)
        if(s[i] == ' ') s[i+1] -= 32;
}