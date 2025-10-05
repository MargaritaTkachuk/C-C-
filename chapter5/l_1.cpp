#include <stdio.h>

double sum(double a) {
    double s = 1.0;
    int n = 1;
    while (s <= a) {
        n++;
        s += 1.0 / n;
    }
    return s;
}

int find_n(double a) {
    double s = 1.0;
    int n = 1;
    while (s <= a) {
        n++;
        s += 1.0 / n;
    }
    return n;
}

int main() {
    double a;
    scanf("%lf", &a);
    printf("a) %.6lf\n", sum(a));
    printf("b) %d\n", find_n(a));
    return 0;
}
