#include <stdio.h>

int main() {
    double a, b, c, d;
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    c = a - b; d = a * b;
    printf("a - b = %.3f\n", c);
    printf("a * b = %.3f\n", d);
}