#include "rational.h"
#include <iostream>
#include <stdexcept>

static long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a < 0 ? -a : a;
}

Rational::Rational() : nominator(1), denominator(1) {}

Rational::Rational(long long n, long long d) {
    if (d == 0) throw std::invalid_argument("Denominator cannot be zero");
    nominator = n;
    denominator = d;
    reduce();
}

void Rational::reduce() {
    long long g = gcd(nominator, denominator);
    nominator /= g;
    denominator /= g;
    if (denominator < 0) {
        denominator = -denominator;
        nominator = -nominator;
    }
}

void Rational::setNominator(long long n) {
    nominator = n;
    reduce();
}

void Rational::setDenominator(long long d) {
    if (d == 0) throw std::invalid_argument("Denominator cannot be zero");
    denominator = d;
    reduce();
}

long long Rational::getNominator() const {
    return nominator;
}

long long Rational::getDenominator() const {
    return denominator;
}

void Rational::input() {
    long long n, d;
    std::cin >> n >> d;
    if (d == 0) throw std::invalid_argument("Denominator cannot be zero");
    nominator = n;
    denominator = d;
    reduce();
}

void Rational::output() const {
    std::cout << nominator << "/" << denominator;
}

Rational Rational::add(const Rational& r) const {
    return Rational(nominator * r.denominator + r.nominator * denominator,
                    denominator * r.denominator);
}

Rational Rational::multiply(const Rational& r) const {
    return Rational(nominator * r.nominator, denominator * r.denominator);
}

Rational Rational::operator+(const Rational& r) const {
    return add(r);
}

Rational Rational::operator*(const Rational& r) const {
    return multiply(r);
}

Rational& Rational::operator+=(const Rational& r) {
    *this = add(r);
    return *this;
}

Rational& Rational::operator*=(const Rational& r) {
    *this = multiply(r);
    return *this;
}

bool Rational::operator==(const Rational& r) const {
    return nominator == r.nominator && denominator == r.denominator;
}

bool Rational::operator!=(const Rational& r) const {
    return !(*this == r);
}

bool Rational::operator<(const Rational& r) const {
    return nominator * r.denominator < r.nominator * denominator;
}

bool Rational::operator>(const Rational& r) const {
    return r < *this;
}

bool Rational::operator<=(const Rational& r) const {
    return !(r < *this);
}

bool Rational::operator>=(const Rational& r) const {
    return !(*this < r);
}
