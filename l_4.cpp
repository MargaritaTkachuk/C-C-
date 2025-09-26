#include <stdio.h>

int main() {
    double x, x_1, q, q_2, q_5;
    double y;
    printf("enter x: ");
    scanf("%lf", &x);
    q = 2 * x;
    q_2 = q * q;
    q_5  = q_2 * q_2 * q;
    x_1 = 1;
    y = x_1 * (q_5 - 1) / (q - 1);
    printf("sum = %lf\n", y);
}