#include <stdio.h>

int main() {
    double a, b, arif, harm;
    printf("Please enter two numbers: ");
    scanf("%lf %lf", &a, &b);
    arif = (a + b) / 2.0;
    harm = 2.0 / (1/a + 1/b);
    printf("(a + b) / 2 = %.4e, %.4f\n", arif, arif);
    printf("2 / (1/a + 1/b) = %.4e, %.4f\n", harm, harm);

}