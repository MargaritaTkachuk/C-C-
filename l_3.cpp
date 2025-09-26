#include <stdio.h>

int main() {
    int a, b, c, prod_a;
    long long prod_b;
    printf("a b c: ");
    int input = scanf("%d %d %d", &a, &b, &c);
    if (input != 3) {
        printf("invalid input\n");
        return 0;
    }
    prod_a = a * b * c;
    prod_b =(long long) a * b * c;
    printf("prod_a = %d\n", prod_a);
    printf("prod_b = %lld\n", prod_b);
}