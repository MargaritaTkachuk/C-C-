#pragma once

#include <iostream>
#include <numeric>
#include <fstream>

class Rational {
private:
    int numerator;
    int denominator;
    void reduce();

public:
    Rational() : numerator(0), denominator(1) {}
    Rational(int num, int den);

    // Гетери та сетери
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
    void setNumerator(int num);
    void setDenominator(int den);

    // Арифметичні оператори
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    // Унарний мінус
    Rational operator-() const;

    // Оператори вводу/виводу
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);

    // Дружня функція для запису у файл
    friend void writeToFile(const Rational& r, const std::string& filename);
};