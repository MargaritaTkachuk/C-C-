#include "ThreeByteInt.h"

void ThreeByteInt::checkRange(int32_t val) {
    if (val < MIN_VALUE || val > MAX_VALUE)
        throw OverflowException();
}

ThreeByteInt::ThreeByteInt(int32_t v) {
    checkRange(v);
    value = v;
}

ThreeByteInt::ThreeByteInt(const ThreeByteInt& other) {
    value = other.value;
}

ThreeByteInt ThreeByteInt::operator+(const ThreeByteInt& other) const {
    int32_t res = value + other.value;
    checkRange(res);
    return ThreeByteInt(res);
}

ThreeByteInt ThreeByteInt::operator-(const ThreeByteInt& other) const {
    int32_t res = value - other.value;
    checkRange(res);
    return ThreeByteInt(res);
}

ThreeByteInt ThreeByteInt::operator*(const ThreeByteInt& other) const {
    int32_t res = value * other.value;
    checkRange(res);
    return ThreeByteInt(res);
}

ThreeByteInt ThreeByteInt::operator/(const ThreeByteInt& other) const {
    if (other.value == 0)
        throw DivisionByZeroException();

    int32_t res = value / other.value;
    checkRange(res);
    return ThreeByteInt(res);
}

ThreeByteInt ThreeByteInt::pow(unsigned int n) const {
    ThreeByteInt result(1);
    ThreeByteInt base = *this;

    for (unsigned int i = 0; i < n; i++) {
        result = result * base;
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const ThreeByteInt& x) {
    os << x.value;
    return os;
}

std::istream& operator>>(std::istream& is, ThreeByteInt& x) {
    int32_t temp;
    is >> temp;
    ThreeByteInt::checkRange(temp);
    x.value = temp;
    return is;
}
