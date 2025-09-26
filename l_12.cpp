#include <stdio.h>

int main() {
    unsigned n;
    double x = 1.0, sum = 1.0, sub;
    printf("n = ");
    scanf("%u", &n);
    for (unsigned i = 1; i <= n; i++) {
        x /= - (double)i;
        sum += x;
    }
    sub = sum;
    for (unsigned i = 2; i <= n; i++) {
        sub *= (double)i;
    }
    printf("%.0lf\n", sub);
}