#include <stdio.h>

int main() {
    unsigned a, b;
    printf("a = ");
    scanf("%u", &a);
    printf("b = ");
    scanf("%u", &b);

    unsigned int m = a | b;
    if (m == 0) {
        printf("Обидва числа = 0\n");
    }

    unsigned int mask = 0;
    unsigned int tmp = m;
    while (tmp) {
        mask = (mask << 1) | 1u;
        tmp >>= 1;
    }

    if ( ((~m) & mask) == 0 )
        printf("%u і %u НЕ мають нульових бітів на однакових позиціях.\n", a, b);
    else
        printf("%u і %u МАЮТЬ нульові біти на однакових позиціях.\n", a, b);
}