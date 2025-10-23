#include <stdio.h>
#include "rational.h"


int gcd(int a, int b) {
    if (b == 0) return a > 0 ? a : -a;
    return gcd(b, a % b);
}

Rational reduce(Rational r) {
    int g = gcd(r.numerator, r.denominator);
    r.numerator /= g;
    r.denominator /= g;
    if (r.denominator < 0) {
        r.denominator = -r.denominator;
        r.numerator = -r.numerator;
    }
    return r;
}

Rational add(Rational a, Rational b) {
    Rational res;
    res.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    res.denominator = a.denominator * b.denominator;
    return reduce(res);
}

Rational multiply(Rational a, Rational b) {
    Rational res;
    res.numerator = a.numerator * b.numerator;
    res.denominator = a.denominator * b.denominator;
    return reduce(res);
}

int compare(Rational a, Rational b) {
    int left = a.numerator * b.denominator;
    int right = b.numerator * a.denominator;
    if (left < right) return -1;
    if (left > right) return 1;
    return 0;
}

int main() {
    Rational a, b, sum, prod;
    scanf("%d %u", &a.numerator, &a.denominator);
    scanf("%d %u", &b.numerator, &b.denominator);
    sum = add(a, b);
    prod = multiply(a, b);
    printf("Сума: %d/%u\n", sum.numerator, sum.denominator);
    printf("Добуток: %d/%u\n", prod.numerator, prod.denominator);
    int cmp = compare(a, b);
    if (cmp == 0) printf("Рівні\n");
    else if (cmp < 0) printf("Перше менше\n");
    else printf("Перше більше\n");
    return 0;
}
