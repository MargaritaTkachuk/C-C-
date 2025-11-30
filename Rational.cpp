#include "Rational.h"
#include <cmath>
#include <stdexcept>

void Rational::reduce() {
    int common_divisor = std::gcd(std::abs(numerator), denominator);
    numerator /= common_divisor;
    denominator /= common_divisor;

    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
}

Rational::Rational(int num, int den) {
    if (den == 0) {
        throw std::invalid_argument("Знаменник не може бути нулем.");
    }
    numerator = num;
    denominator = den;
    reduce();
}

void Rational::setNumerator(int num) {
    numerator = num;
    reduce();
}

void Rational::setDenominator(int den) {
    if (den == 0) {
        throw std::invalid_argument("Знаменник не може бути нулем.");
    }
    denominator = den;
    reduce();
}

// Арифметичні оператори
Rational Rational::operator+(const Rational& other) const {
    int new_denominator = denominator * other.denominator;
    int new_numerator = (numerator * other.denominator) + (other.numerator * denominator);
    return Rational(new_numerator, new_denominator);
}

Rational Rational::operator-(const Rational& other) const {
    int new_denominator = denominator * other.denominator;
    int new_numerator = (numerator * other.denominator) - (other.numerator * denominator);
    return Rational(new_numerator, new_denominator);
}

Rational Rational::operator-() const {
    return Rational(-numerator, denominator);
}

Rational Rational::operator*(const Rational& other) const {
    int new_numerator = numerator * other.numerator;
    int new_denominator = denominator * other.denominator;
    return Rational(new_numerator, new_denominator);
}

Rational Rational::operator/(const Rational& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Ділення на нульовий дріб неможливе.");
    }
    int new_numerator = numerator * other.denominator;
    int new_denominator = denominator * other.numerator;
    return Rational(new_numerator, new_denominator);
}

// Оператори вводу/виводу
std::ostream& operator<<(std::ostream& os, const Rational& r) {
    if (r.denominator == 1) {
        os << r.numerator;
    } else {
        os << r.numerator << "/" << r.denominator;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {
    char slash;
    is >> r.numerator >> slash;

    if (slash != '/') {
        is.setstate(std::ios::failbit);
        return is;
    }

    is >> r.denominator;

    if (r.denominator == 0) {
        throw std::invalid_argument("Знаменник не може бути нулем.");
    }

    r.reduce();
    return is;
}

// Дружня функція для запису у файл
void writeToFile(const Rational& r, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Не вдалося відкрити файл: " + filename);
    }

    file << r.numerator << " " << r.denominator;
    file.close();
}