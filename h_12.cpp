#include <stdio.h>

int main() {
    double a, b, c, d, e, f, g;
    a = 1 + 1/3;
    b = 1/a;
    c = 7 + b;
    d = 1/c;
    e = 4 + d;
    f = 1/e;
    g = 365 + f;
    printf("T = %g\n", g);
}