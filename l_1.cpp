#include <stdio.h>

int main() {
    unsigned n, ones, tens, hundreds, sum, reversed;
    printf("n = ");
    scanf("%u", &n);
    if (n >= 100 and n <= 999) {
        ones = n % 10;
        tens = (n % 100) / 10;
        hundreds = n / 100;
        sum = ones + tens + hundreds;
        reversed = ones * 100 + tens * 10 + hundreds;
        printf("%u : %uo %ut %uh\n", n, ones, tens, hundreds);
        printf("sum = %u\n", sum);
        printf("reversed = %u\n", reversed);
    }


}