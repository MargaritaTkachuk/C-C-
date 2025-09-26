#include <stdio.h>
#include <math.h>

double f_a(unsigned n, double x) {
    double res = 1;
    for (unsigned i = n; i > 0 ; i--) {
        res += pow(x, i);
    }
    return res;
}

double f_b(unsigned n, double x, double y) {
    double res = 1;
    for (unsigned i = n; i > 0 ; i--) {
        res += pow(x, pow(2, i)) * pow(y, i);
    }
    return res;
}

int main() {
    double y1, y2;
    int n1 = 3, x1 = 2, n2 = 4, x2 = 1, y = 2;
    y1 = f_a(n1, x1);
    y2 = f_b(n2, x2, y);
    printf("y1 = %g\n", y1);
    printf("y2 = %g\n", y2);






}