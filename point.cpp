#include "point.h"
#include <cmath>

int Point::countInstances = 0;

Point::Point() : x(0), y(0) { countInstances++; }

Point::Point(double x, double y) : x(x), y(y) { countInstances++; }

int Point::counter() {
    return countInstances;
}

double Point::distance(const Point& other) const {
    return std::sqrt((x - other.x)*(x - other.x) + (y - other.y)*(y - other.y));
}
