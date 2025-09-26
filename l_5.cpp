#include <stdio.h>

int main() {
    unsigned long long n, res;
    printf("n = ");
    scanf("%u", &n);
    res = 1ULL;
    for (unsigned i = n; i > 1; i -= 2) {
        res *= i;
    }
    printf("%u!! = %llu\n", n, res);
}