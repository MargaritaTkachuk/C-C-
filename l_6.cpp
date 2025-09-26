#include <stdio.h>

int main() {
    double C;
    double F;
    printf("degree in C: ");
    scanf("%lf", &C);
    F = C * 1.8 + 32;
    printf("F = %g\n", F);
}