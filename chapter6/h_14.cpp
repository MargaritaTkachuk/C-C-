#include <stdio.h>

int main() {
    unsigned n;
    printf("n = ");
    scanf("%u",&n);

    if (n != 0 && (n & (n - 1)) == 0) {
        printf("power of 2\n");
    }
    else {
        printf("not power of 2\n");
    }

    unsigned x = 1;
    while (x < n) {
        x = x << 1;
    }
    if (x == n) {
        printf("power of 2\n");
    }
    else {
        printf("not power of 2\n");
    }

}