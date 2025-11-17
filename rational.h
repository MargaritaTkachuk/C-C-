#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
    long long nominator;
    long long denominator;
    void reduce();
public:
    Rational();
    Rational(long long n, long long d);
    void setNominator(long long n);
    void setDenominator(long long d);
    long long getNominator() const;
    long long getDenominator() const;

    void input();
    void output() const;

    Rational add(const Rational& r) const;
    Rational multiply(const Rational& r) const;

    Rational operator+(const Rational& r) const;
    Rational operator*(const Rational& r) const;

    Rational& operator+=(const Rational& r);
    Rational& operator*=(const Rational& r);

    bool operator==(const Rational& r) const;
    bool operator!=(const Rational& r) const;
    bool operator<(const Rational& r) const;
    bool operator>(const Rational& r) const;
    bool operator<=(const Rational& r) const;
    bool operator>=(const Rational& r) const;
};

#endif
