#include <stdio.h>

int main() {
    int n;

    printf("n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("n < 0\n");
        return 1;
    }

    double P_a = 1.0;
    double fact = 1.0;
    for (int i = 1; i <= n; i++) {
        fact *= i;
        double a_i = 1.0 + 1.0 / fact;
        P_a *= a_i;
    }

    double P_b = 1.0;
    double power_of_2 = 1.0;
    for (int i = 1; i <= n; i++) {
        power_of_2 *= 2;
        int sign = (i % 2 == 1) ? 1 : -1;
        double numerator = sign * i * i;
        double a_i = 1.0 + numerator / power_of_2;
        P_b *= a_i;
    }

    printf("Результат (а): P_%d = %.10f\n", n, P_a);
    printf("Результат (б): P_%d = %.10f\n", n, P_b);

    return 0;
}