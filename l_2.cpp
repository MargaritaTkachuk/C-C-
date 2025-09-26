#include <stdio.h>

int main() {
    unsigned n, ones, tens, hundreds;
    printf("n = ");
    scanf("%u", &n);
    if (n >= 100 and n <= 999) {
        ones = n % 10;
        tens = (n % 100) / 10;
        hundreds = n / 100;
        if (ones != tens and tens != hundreds and ones != hundreds) {
            unsigned n1, n2, n3, n4, n5, n6;
            n1 = n;
            n2 = 100 * hundreds + 10 * ones + tens;
            n3 = 100 * tens + 10 * ones + hundreds;
            n4 = 100 * tens + 10 * hundreds + ones;
            n5 = 100 * ones + 10 * hundreds + tens;
            n6 = 100 * ones + 10 * tens + hundreds;
            printf("%u\n", n1);
            printf("%u\n", n2);
            printf("%u\n", n3);
            printf("%u\n", n4);
            printf("%u\n", n5);
            printf("%u\n", n6);

        }
    }


}