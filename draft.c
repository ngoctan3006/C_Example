#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char id[10];
    char name[100];
    float math;
    float physic;
};

uint8_t strToInt(uint8_t *str) {
    uint32_t res = 0;
    uint8_t len = strlen(str);
    uint8_t temp;
    for (uint8_t i = 0; i < len; i++) {
        temp = str[i];
        if (isdigit(temp))
            temp -= '0';
        else if (isalpha(temp)) {
            temp = toupper(temp);
            temp = temp - 'A' + 10;
        } else
            return 0xff;
        res = res * 16 + temp;
    }
    return res;
}

int main(int argc, char** argv) {
    int a[10];
    for (int i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    return 0;
}


/**
 * 0xff = 255 = 1111 1111 
*/


// typedef struct NODE {
//     int data;
//     struct NODE *left;
//     struct NODE *right;
// }node;
// node *createTreeNode(int x) {
//     node *p = (node *) malloc(sizeof(node));
//     p->data = x;
//     p->left = NULL;
//     p->right = NULL;
//     return p;
// }
// node *addTreeNode(node *r, int x) {
//     node *p = createTreeNode(x);
//     if(r == NULL) return p;
//     if( x < r->data) r->left = addTreeNode(r->left, x);
//     if(x >= r->data) r->right = addTreeNode(r->right, x);
//     return r;
// }
// node *findTreeNode(node *r, int x) {
//     if(r == NULL) return NULL;
//     if(r->data == x) return r;
//     if(x < r->data) return findTreeNode(r->left, x);
//     return findTreeNode(r->right, x);
// }
// void freeTreeNode(node *r) {
// 	if(r == NULL) return;
// 	freeTreeNode(r->left);
// 	freeTreeNode(r->right);
//     free(r);
// }
// node *deleteNumber(node *r, int x) {
// 	node *cur = findTreeNode(r, x);
// 	if(cur != NULL)
// 		freeTreeNode(cur);
// 	return r;
// }
// void printfInOrder(node *r) {
//     if(r == NULL) return;
//     printfInOrder(r->left);
//     printf("%d ", r->data);
//     printfInOrder(r->right);
// }
// int main() {
//     int n, i, a;
//     node *r = NULL;
//     scanf("%d", &n);
//     for(i =0; i< n; i++) {
//         scanf("%d", &a);
//         r = addTreeNode(r, a);
//     }
//     int giatricanxoa;
//     scanf("%d", &giatricanxoa);
// 	r = deleteNumber(r, giatricanxoa);
// 	if( r == NULL) printf("NULL");
// 	else printfInOrder(r);
//     return 0;
// }

// int main() {
//     int a[5] = {1, 2, 3, 4, 5};
//     int* b = a;
//     printf("%d ", b[0]);
//     printf("%d ", b[1]);
//     printf("%d ", b[2]);
//     return 0;
// }

// int main() {
//     char s[100];
//     char *charBuff = (char *) malloc(sizeof(char));
//     char *digitBuff = (char *) malloc(sizeof(char));
//     int charCount = 0, digitCount = 0;
//     scanf("%[^\n]s", s);
//     int len = strlen(s), i = 0;
//     for(; i < len; i++) {
//         if(isalpha(*(s + i))) {
//             *(charBuff + charCount*sizeof(char)) = *(s + i);
//             charCount++;
//             charBuff = (char *) realloc(charBuff, charCount*sizeof(char));
//         } else if(isdigit(*(s + i))) {
//             *(digitBuff + digitCount*sizeof(char)) = *(s + i);
//             digitCount++;
//             digitBuff = (char *) realloc(digitBuff, digitCount*sizeof(char));
//         }
//     }
//     *(charBuff + charCount*sizeof(char)) = '\0';
//     *(digitBuff + digitCount*sizeof(char)) = '\0';
//     printf("%s\n%s", charBuff, digitBuff);
// char s1[] = "DHBK";
// char s2[] = {'D', 'H', 'B', 'K'};
// printf("%x\n", s1);
// printf("%x\n", s2);
// printf("%d", strcmp(s1, s2));
// int a[5] = {1, 2};
// int b = 1;
// printf("%d", (int) sizeof(a));
// int j = 3, k = 2, p;
// float r = 2.0f, q = 7.2f, a;
// a = j/k;
// p = q/r;
// printf("%f\n%f", a, p);
// int i = 1;
// i <<= 7;
// i >>=7;
// printf("%d\n", i);
// double d = 1.28;
// printf("%x\n", d);
// char a = 154, b = 170;
// char c = a + b;
// printf("%d\n", c);
// int a, b, c;
// scanf("%d%d%d", &a, &b, &c);
// printf("a = %d\nb = %d\nc = %d\n", a, b, c);
// int s = 0;
// int a[3][4] = {{1, 3, 5}, {4, 5}, {2}};
// for(int i = 0; i < 3; i++) s += a[i][i];
// while (i>1) {
//     switch (i%3) {
//         case 1: i = i/2 + 1; break;
//         case 0: printf("%d ", i);
//         default: i -= 2; printf("%d ", i+1);
//     }
// }
// int s = 0;
// for(int i = 0; i < 10; i++) {
//     if(i%3) s += i;
//     else i += 3;
// }
// printf("%d\n", s);
// char s[10] = "hello";
// s = "hello";
// le   THI   cAm   lY   => Le Thi Cam Ly

// char s[10] = "Hello :))";
// // char s[10];
// int len = strlen(s);
// printf("%d", len);
// printf("%d\n", strcmp("BYTE", "byte"));
// printf("%d\n", strcmp("byte", "byte"));
// printf("%d\n", strcmp("byte", "BYTE"));
// int a = 0b111, b = 2;
// a = (--b>a) ? b++:++b;
// int a = 7+5&&3<=1+3-2.0/3&&5<2+1;
// a = 7+1<=3<2+1;
// // a = 2.0/3&&5;
// a = 1+2 < 2+3 && 1;
// printf("%d", a);
// int a, b, c
// // a = 12;
// // b = 234;
// printf("Nhap a va b: ");
// scanf("%d%d", &a, &b);
// c = a + b;
// printf("Tong cua a va b la: %d", c);
// float x, y;
// x = 1.234;
// printf("%f\n", x);
// printf("Hello");
// return 1;
// }

/* -7 -6 -5 .. -1 0 1 2 .. 6
10 -> 1010 11111111
char: kí tự %c || 1 byte = 8 bit || -2^7 -> 2^7-1
int: %d || 4 byte = 32 bit || -2^31 -> 2^31-1
unsigned int: %ud || 4 byte = 32 bit || 0 -> 2^32-1
long long: %lld
float: %f
double: %lf
*/

// int soLui(int n) {
//     int m;
//     while(n > 9) {
//         m = n%10;
//         n /= 10;
//         if(m >= n%10) return 0;
//     }
//     return 1;
// }
// int main() {
//     int n;
//     scanf("%d", &n);
//     if(soLui(n)) printf("La so lui");
//     else printf("Khong phai so lui");
//     return 0;
// }

// int main() {
//     int a, d = 0x80;
//     scanf("%d", &a);
//     for(int i = 0; i < 8; i++) {
//         printf("%d", a&d ? 1:0);
//         d >>= 1;
//     }
//     return 0;
// }

// int isPrime(int n) {
//     if(n < 2) return 0;
//     for(int i = 2; i <= sqrt(n); i++) {
//         if(n%i == 0) return 0;
//     }
//     return 1;
// }
// int main() {
//     for(int i = 2; i < 100; i++) {
//         if(isPrime(i)) printf("%d ", i);
//     }
//     return 0;
// }

// int reverse(int n) {
//     int res = 0;
//     while(n > 0) {
//         res = res*10 + n%10;
//         n /= 10;
//     }
//     return res;
// }
// int main() {
//     int a;
//     scanf("%d", &a);
//     if(isPrime(a) && isPrime(reverse(a))) printf("La so emirp\n");
//     else printf("Khong phai so emirp\n");
//     return 0;
// }

// int main() {
//     int a, b = 0;
//     scanf("%d", &a);
//     if(a < 2) {
//         printf("Khong phai so emirp\n");
//         return 0;
//     }
//     for(int i = 2; i <= sqrt(a); i++) {
//         if(a%i == 0) {
//             printf("Khong phai so emirp\n");
//             return 0;
//         }
//     }
//     while(a > 0) {
//         b = b*10 + a%10;
//         a /= 10;
//     }
//     for(int i = 2; i <= sqrt(b); i++) {
//         if(b%i == 0) {
//             printf("Khong phai so emirp\n");
//             return 0;
//         }
//     }
//     printf("La so emirp\n");
//     return 0;
// }

// int main() {
//     int n;
//     scanf("%d", &n);
//     int sum = 1;
//     for(int i = 2; i <= n/2; i++) {
//         if(n%i == 0) sum += i;
//     }
//     if(n == sum) printf("La so hoan hao\n");
//     else printf("Khong phai so hoan hao\n");
//     return 0;
// }

// int main() {
//     int n;
//     scanf("%d", &n);
//     while(n > 0) {
//         if((n%10) % 2 == 0) {
//             printf("Khong phai so le hoan toan\n");
//             return 0;
//         }
//         n /= 10;
//     }
//     printf("La so le hoan toan\n");
//     return 0;
// }

// int leHoanToan(int n) {
//     while(n > 0) {
//         if((n%10) % 2 == 0) return 0;
//         n /= 10;
//     }
//     return 1;
// }
// int main() {
//     int n;
//     scanf("%d", &n);
//     if(leHoanToan(n)) printf("%d la so le hoan toan\n", n);
//     else printf("%d khong phai so le hoan toan\n", n);
//     return 0;
// }

// int count(int n) {
//     if(n/10 == 0) return 1;
//     else return 1 + count(n/10);
// }
// int main() {
//     int n;
//     scanf("%d", &n);
//     printf("So chu so cua %d la: %d", n, count(n));
//     return 0;
// }

// int main(){
//     int x = 20, y = 35;
//     x = y++ + x++;
//     y = ++y + ++x;
//     printf("%d %d", x, y);
//     return 0;
// }