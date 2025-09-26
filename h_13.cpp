#include <stdio.h>

int main() {
    double a1, b1, c1, a2, b2, c2;
    printf("Enter coefficients a1, b1, c1: ");
    scanf("%lf %lf %lf", &a1, &b1, &c1);
    printf("Enter coefficients a2, b2, c2: ");
    scanf("%lf %lf %lf", &a2, &b2, &c2);

    double D = a1 * b2 - a2 * b1;
    double Dx = (-c1) * b2 - (-c2) * b1;
    double Dy = a1 * (-c2) - a2 * (-c1);

    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        printf("System has one solution:\n");
        printf("x = %g, y = %g\n", x, y);
    } else {
        if (a1 * b2 == a2 * b1 && a1 * c2 == a2 * c1 && b1 * c2 == b2 * c1) {
            printf("System has infinitely many solutions\n");
        } else {
            printf("System has no solutions\n");
        }
    }

    return 0;
}
