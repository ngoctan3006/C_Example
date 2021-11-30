#include <stdio.h>

int main(int argc, char *argv[]) {
    if(argc <= 1) {
        printf("Khong co tham so nao\n");
    } else {
        printf("Cac tham so duoc nhap vao:\n");
        for(int i = 1; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
    }
}
