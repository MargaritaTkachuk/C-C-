#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Введіть n: ");
    scanf("%d", &n);


    double a1 = 0.0, a2 = 1.0;
    double b1 = 1.0, b2 = 0.0;
    double a_prev2 = a1, a_prev1 = a2;
    double b_prev1 = b2;

    double S = 0.0;


    if (n >= 1) {
        S += pow(2, 1) / (a1 + b1);
        printf("k=1: a1=%.6f, b1=%.6f, доданок=%.6f, S=%.6f\n", a1, b1, pow(2,1)/(a1+b1), S);
    }

    if (n >= 2) {
        S += pow(2, 2) / (a2 + b2);
        printf("k=2: a2=%.6f, b2=%.6f, доданок=%.6f, S=%.6f\n", a2, b2, pow(2,2)/(a2+b2), S);
    }

    for (int k = 3; k <= n; k++) {

        double b_k = b_prev1 + a_prev1;

        double a_k = (a_prev1 / k) + a_prev2 * b_k;

        double term = pow(2, k) / (a_k + b_k);
        S += term;

        printf("k=%d: a%d=%.6f, b%d=%.6f, доданок=%.6f, S=%.6f\n",
               k, k, a_k, k, b_k, term, S);

        a_prev2 = a_prev1;
        a_prev1 = a_k;
        b_prev1 = b_k;
    }

    printf("\nРезультат: S_%d = %.10f\n", n, S);

    return 0;
}