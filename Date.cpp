#include "Date.h"
#include <cstdlib>

Date* Date::instance = nullptr;

Date::Date(int y, int m, int d) : y(y), m(m), d(d) {}

Date* Date::getInstance(int y, int m, int d) {
    if (!instance)
        instance = new Date(y, m, d);
    return instance;
}

int Date::daysFromStart() const {
    return y * 365 + (m - 1) * 30 + d;
}

int Date::difference(const Date& other) const {
    return std::abs(this->daysFromStart() - other.daysFromStart());
}
