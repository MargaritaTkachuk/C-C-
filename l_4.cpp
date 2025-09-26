#include <stdio.h>
#include <math.h>

int main() {
    unsigned n;
    double x, x_1, sum;
    printf("n = ");
    scanf("%u", &n);
    printf("x = ");
    scanf("%lf", &x);
    x_1 = x;
    sum = x;
    for (unsigned i = 2; i <= n; i++) {
        x_1 *= x;
        sum += i * x_1;
    }

    printf("sum = %lf\n", sum);

}