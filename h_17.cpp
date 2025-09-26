#include <stdio.h>
#include <math.h>

double softPlus(double x) {
    return log(1.0 + exp(x));
}

double derivative(double x) {
    return exp(x) / (1.0 + exp(x));
}

int main() {
    double x, soft, deriv;
    printf("x = ");
    scanf("%lf", &x);
    soft = softPlus(x);
    deriv = derivative(x);
    printf("softPlus(%lf) = %lf\n", x, soft);
    printf("derivative(%lf) = %lf", x, deriv);

}