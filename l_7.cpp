#include <stdio.h>
#include <math.h>

double desc(double a, double b, double c) {
    return b * b - 4 * a * c;
}

unsigned solve_quad(double a, double b, double c, double *x1, double *x2) {
    if (a == 0.0) {
        if (b != 0.0) {
            *x1 = -c / b;
            return 1;
        }
        return 0;
    }

    double D = desc(a, b, c);
    if (D < 0.0) return 0;
    else if (D == 0.0) {
        *x1 = -b / (2 * a);
        return 1;
    }
    else {
        *x1 = (-b - sqrt(D)) / (2 * a);
        *x2 = (-b + sqrt(D)) / (2 * a);
        return 2;
    }
}

unsigned solve_quartic(double a, double b, double c,
                       double *r1, double *r2, double *r3, double *r4) {
    double y1, y2;
    unsigned countY = solve_quad(a, b, c, &y1, &y2);
    unsigned countX = 0;

    if (countY >= 1) {
        if (y1 > 0) {
            *r1 = sqrt(y1);
            *r2 = -sqrt(y1);
            countX += 2;
        } else if (y1 == 0) {
            *r1 = 0;
            countX += 1;
        }
    }

    if (countY == 2) {
        if (y2 > 0) {
            if (countX == 0) {
                *r1 = sqrt(y2);
                *r2 = -sqrt(y2);
            } else {
                *r3 = sqrt(y2);
                *r4 = -sqrt(y2);
            }
            countX += 2;
        } else if (y2 == 0) {
            if (countX == 0) *r1 = 0;
            else *r3 = 0;
            countX += 1;
        }
    }

    return countX;
}

int main() {
    double a, b, c;
    printf("Enter coefficients a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double x1, x2;
    unsigned cnt = solve_quad(a, b, c, &x1, &x2);
    printf("\nQuadratic equation: ");
    if (cnt == 0) printf("no real solutions\n");
    else if (cnt == 1) printf("one solution: x = %g\n", x1);
    else printf("two solutions: x1 = %g, x2 = %g\n", x1, x2);

    double r1, r2, r3, r4;
    unsigned cnt4 = solve_quartic(a, b, c, &r1, &r2, &r3, &r4);
    printf("\nBi-quadratic equation: ");
    if (cnt4 == 0) printf("no real solutions\n");
    else {
        printf("%u solution(s):\n", cnt4);
        if (cnt4 >= 1) printf("x1 = %g\n", r1);
        if (cnt4 >= 2) printf("x2 = %g\n", r2);
        if (cnt4 >= 3) printf("x3 = %g\n", r3);
        if (cnt4 == 4) printf("x4 = %g\n", r4);
    }

    return 0;
}
