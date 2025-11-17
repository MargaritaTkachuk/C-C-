#include "Time.h"
#include <cmath>

Time::Time(int h, int m, int s) : h(h), m(m), s(s) {}

int Time::toSeconds() const {
    return h * 3600 + m * 60 + s;
}

int Time::difference(const Time& other) const {
    return std::abs(this->toSeconds() - other.toSeconds());
}
