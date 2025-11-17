#ifndef POINT_H
#define POINT_H

class Point {
    double x, y;
    static int countInstances;
public:
    Point();
    Point(double, double);
    static int counter();
    double distance(const Point&) const;
};

#endif
