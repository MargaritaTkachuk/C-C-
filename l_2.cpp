#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    printf("enter a b: ");
    scanf("%lf %lf", &a, &b);
    c = sqrt(a * a + b * b);
    printf("c = %lf\n", c);

}
