#include <stdio.h>
#include <math.h>

int main() {
    double d, h;
    printf("d = ");
    scanf("%lf", &d);
    printf("h = ");
    scanf("%lf", &h);


    for (double x = -3.0; x <= 3.0 + 1e-12; x += h) {
        double y = exp(-d * x * x);
        printf("x = %.6f : exp(-d*x^2) = %.6f\n", x, y);
    }

}
