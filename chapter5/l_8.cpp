#include <stdio.h>
#include <math.h>

double exp_taylor(double x, double epsilon) {
    double sum = 1.0;
    double term = 1.0;
    int n = 1;

    while (fabs(term) >= epsilon) {
        term = term * x / n;
        sum += term;
        n++;
    }

    return sum;
}

double phi_taylor(double x, double epsilon) {
    double sum = x;
    double term = x;
    int n = 1;

    while (fabs(term) >= epsilon) {
        term = term * (-1) * x * x / (2 * n + 1);
        sum += term;
        n++;
    }

    return sum;
}

int main() {
    double epsilon, x;

    printf("Введіть додатню точність ε: ");
    scanf("%lf", &epsilon);

    if (epsilon <= 0) {
        printf("Точність має бути додатньою!\n");
        return 1;
    }

    printf("Введіть x: ");
    scanf("%lf", &x);

    double exp_taylor_result = exp_taylor(x, epsilon);
    double exp_math_result = exp(x);

    printf("Результат ряду Тейлора: %.10f\n", exp_taylor_result);
    printf("Результат math.h exp(): %.10f\n", exp_math_result);

    double phi_taylor_result = phi_taylor(x, epsilon);
    double phi_math_result = (sqrt(M_PI) / 2) * erf(x);

    printf("Результат ряду Тейлора: %.10f\n", phi_taylor_result);
    printf("Результат через erf(x): %.10f\n", phi_math_result);

}