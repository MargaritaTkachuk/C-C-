#include <stdio.h>
#include <math.h>

double softExponential(double a, double x) {
    double f;
    if (a < 0.0){
        f = - log(1.0 - a * (x + a)) / a;
    }
    else if (a == 0.0) {
        f = x;
    }
    else {
        f = (exp(a * x) - 1) / a + a;
    }
    return f;
}

double d_softExponential(double a, double x) {
    double f;
    if (a < 0.0){
        f = 1 / (1.0 - a * (x + a));
    }
    else if (a == 0.0) {
        f = 1.0;
    }
    else {
        f = exp(a * x);
    }
    return f;
}

int main() {
    double a, x;
    printf("a, x: ");
    scanf("%lf %lf", &a, &x);
    double ans = softExponential(a, x);
    double ans2 = d_softExponential(a, x);
    printf("f = %lf\n", ans);
    printf("f' = %lf\n", ans2);

}