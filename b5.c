#include <stdio.h>
#include <math.h>

// int main() {
//     int n, a[1000], sum, check, temp;
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//     }
//     for(int i = 0; i < n; i++) {
//         sum = 0;
//         temp = a[i];
//         while(temp != 0) {
//             sum += temp%10;
//             temp /= 10;
//         }
//         check = 1;
//         if(sum < 2) check = 0;
//         for(int j = 2; j < sqrt(sum); j++) {
//             if(sum % j == 0) {
//                 check = 0;
//                 break;
//             }
//         }
//         if(check) printf("%d ", a[i]);
//     }
//     return 0;
// }

// int main() {
//     int n, sum = 0;
//     scanf("%d", &n);
//     while(n != 0) {
//         sum += n%10;
//         n /= 10;
//     }
//     printf("%d\n", sum);
//     return 0;
// }

// int main() {
//     int n, check = 1;
//     scanf("%d", &n);
//     if(n < 2) {
//         check = 0;
//     }
//     for(int i = 2; i < sqrt(n); i++) {
//         if(n % i == 0) {
//             check = 0;
//             break;
//         }
//     }
//     if(check) printf("%d la so nguyen to\n", n);
//     else printf("%d khong la so nguyen to\n", n);
//     return 0;
// }

// int main()
// {
//     char S[1001];
//     fgets(S, 1001, stdin);
//     int lenS = 0, len = 0;
//     while(S[lenS] == ' ') ++lenS;
//     while(S[lenS] != '\0' && S[lenS] != '\n') {
//         if(S[lenS] == 32 && S[lenS + 1] != 32 && S[lenS + 1] != '\0' && S[lenS + 1] != '\n')
//             printf(" "), ++len;
//         else if(S[lenS] != 32 && S[lenS] != '\0' && S[lenS] != '\n') {
//             if(isalpha(S[lenS])) printf("%c", toupper(S[lenS]));
//             // else printf("%c", S[lenS]);
//             ++len;
//         }
//         ++lenS;
//     }
//     printf(":%d", len);
//     return 0;
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
// 	char tg[20],s[100], t[100];
// 	int n,i,j;
// 	fgets(s,100,stdin);
// 	fgets(t,100,stdin);
// 	n=strlen(s);
// 	for(i=0;i<n-1;i=i+1)
// 		for(j=1;j<n;j=j+1)
// 			{
// 				if (strcmp(s[i],s[j])>0)
// 					{
// 						strcpy(tg,s[i]);
// 						strcpy(s[i],s[j]);
// 						strcpy(s[j],tg);
// 					}
// 			}	
// 		puts(s);
		
// return 0;	
// }


// #include<stdio.h>
// #include<string.h>
 
// void count_letters(char *s)
// {
//     int i;
//     int size=strlen(s);
//     int count[26]= {0};
//     for(int i = 0; i < size; i++)
//         count[s[i]-'a']++;
//     for(int i = 0; i < 26; i++)
//         if(count[i] > 0) printf("%c", i+'a');
//     printf("\n");
//     for(int i = 0; i < 26; i++)
//         if(count[i] > 0) printf("%d\n", count[i]);
// }
// int main()
// {
//     char s[200];
//     char t[100];
//     fgets(s,99,stdin);
//     s[strlen(s)-1]  = '\0';
//     fgets(t,99,stdin);
//     t[strlen(s)-1]  = '\0';
//     strcat(s,t);
//     count_letters(s);
//     return 0;
// }