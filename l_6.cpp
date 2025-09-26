#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    printf("Enter 3 numbers: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Invalid input\n");
        return 0;
    }

    if (fabs(a) >= fabs(b) && fabs(a) >= fabs(c)) {
        printf("Largest by absolute value: %lf\n", a);
        if (fabs(b) <= fabs(c)) {
            printf("Smallest by absolute value: %lf\n", b);
        } else {
            printf("Smallest by absolute value: %lf\n", c);
        }
    } else if (fabs(b) >= fabs(a) && fabs(b) >= fabs(c)) {
        printf("Largest by absolute value: %lf\n", b);
        if (fabs(a) <= fabs(c)) {
            printf("Smallest by absolute value: %lf\n", a);
        } else {
            printf("Smallest by absolute value: %lf\n", c);
        }
    } else {
        printf("Largest by absolute value: %lf\n", c);
        if (fabs(a) <= fabs(b)) {
            printf("Smallest by absolute value: %lf\n", a);
        } else {
            printf("Smallest by absolute value: %lf\n", b);
        }
    }

    return 0;
}
