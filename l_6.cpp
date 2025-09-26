#include <stdio.h>
#include <math.h>

double f_a(unsigned n) {
    double res = 0.0;
    for (unsigned i = 1; i <= n; i++) {
        res = sqrt(res + 2.0);
    }
    return res;
}

double f_b(unsigned n) {
    double res = 0.0;
    for (unsigned i = n; i >= 1; i--) {
        res = sqrt(3.0 * (double)i + res);
    }
    return res;
}

int main() {
    unsigned n;
    printf("n = ");
    scanf("%u", &n);
    printf("%lf\n", f_a(n));
    printf("%lf\n", f_b(n));

}