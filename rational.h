#ifndef RATIONAL_H
#define RATIONAL_H

typedef struct {
    int numerator;
    unsigned int denominator;
} Rational;

int gcd(int a, int b);
Rational reduce(Rational r);
Rational add(Rational a, Rational b);
Rational multiply(Rational a, Rational b);
int compare(Rational a, Rational b);

#endif
