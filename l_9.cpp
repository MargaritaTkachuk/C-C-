#include <stdio.h>

int main() {
    unsigned long long n, k = 1ULL;
    unsigned r = 0;
    printf("n = ");
    scanf("%llu", &n);
    while (k <= n) {
        k *= 2ULL;
        r++;
    }
    printf("2^%u > %llu", r, n);
}