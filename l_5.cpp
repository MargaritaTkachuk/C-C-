#include <stdio.h>

int main() {
    double a, b;
    printf("Enter 2 numbers: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Invalid input\n");
        return 0;
    }

    if (a > b) {
        printf("Big: %lf\n", a);
        printf("Small: %lf\n", b);
    }
    else if (a < b) {
        printf("Big: %lf\n", b);
        printf("Small: %lf\n", a);
    }
    else {
        printf("Numbers are equal: %lf\n", a);
    }

    return 0;
}
