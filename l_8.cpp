#include <stdio.h>
#include <math.h>

int main() {
    unsigned long long m, r = 1ULL;
    unsigned k = 0;
    printf("m = ");
    scanf("%llu", &m);
    while (r <= m / 4ULL) {
        r *= 4ULL;
        k++;
    }
    printf("4^%u <= %llu", k, m);
}