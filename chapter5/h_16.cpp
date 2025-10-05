#include <stdio.h>
#include <math.h>

int main() {
    double eps = 1e-8;
    double ak = 1.0, sum = 1.0, i = 1.0;
    double x;
    printf("x = ");
    scanf("%lf", &x);
    while (fabs(ak) >= eps) {
        ak *= -(2*i - 1) * x / (2 * i);
        sum += ak;
        i++;
    }
    printf("y = %lf", sum);
}