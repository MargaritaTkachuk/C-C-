#ifndef THREEBYTEINT_H
#define THREEBYTEINT_H

#include "Exceptions.h"
#include <iostream>

class ThreeByteInt {
private:
    static const int32_t MIN_VALUE = -(1 << 23);
    static const int32_t MAX_VALUE =  (1 << 23) - 1;

    int32_t value;

    static void checkRange(int32_t val);

public:
    ThreeByteInt(int32_t v = 0);
    ThreeByteInt(const ThreeByteInt& other);

    // Оператори
    ThreeByteInt operator+(const ThreeByteInt& other) const;
    ThreeByteInt operator-(const ThreeByteInt& other) const;
    ThreeByteInt operator*(const ThreeByteInt& other) const;
    ThreeByteInt operator/(const ThreeByteInt& other) const;

    // Піднесення до степеня
    ThreeByteInt pow(unsigned int n) const;

    // Доступ
    int32_t get() const { return value; }

    // Ввід / вивід
    friend std::ostream& operator<<(std::ostream& os, const ThreeByteInt& x);
    friend std::istream& operator>>(std::istream& is, ThreeByteInt& x);
};

#endif
