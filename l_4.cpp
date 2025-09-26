#include <stdio.h>

unsigned short prod(unsigned char a, unsigned char b) {
    unsigned int temp = (unsigned int)a * (unsigned int)b;
    if (temp <= 65535) {
        return (unsigned short)temp;
    } else {
        return 0;
    }
}

int main() {
    unsigned char x, y;
    printf("a b : ");
    if (scanf("%hhu %hhu", &x, &y) != 2) {
        printf("invalid input\n");
        return 0;
    }

    unsigned short result = prod(x, y);
    printf("product = %hu\n", result);

    return 0;
}
