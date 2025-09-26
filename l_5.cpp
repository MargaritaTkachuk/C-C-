#include <stdio.h>

double Rosenbrock2d(double x, double y) {
    return (100 * (x * x - y) * (x * x - y) + (x - 1) * (x - 1));
}

int main() {
    double x1, y1, x2, y2, x3, y3, f1, f2, f3;
    printf("enter x y: ");
    scanf("%lf %lf", &x1, &y1);
    printf("enter x y: ");
    scanf("%lf %lf", &x1, &y1);
    printf("enter x y: ");
    scanf("%lf %lf", &x1, &y1);
    f1 = Rosenbrock2d(x1, y1);
    f2 = Rosenbrock2d(x2, y2);
    f3 = Rosenbrock2d(x3, y3);
    printf("f1 = %lf\nf2 = %lf\nf3 = %lf\n", f1, f2, f3);
}