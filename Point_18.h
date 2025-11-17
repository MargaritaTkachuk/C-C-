#ifndef POINT_18_H
#define POINT_18_H

#include <vector>

class Point_18 {
    double x0, y0;
    double vx, vy;
    double ax, ay;

public:
    Point_18(double x0=0, double y0=0);
    void setVelocity(double vx, double vy);
    void setAcceleration(double ax, double ay);
    void getVelocity(double &vx_out, double &vy_out) const;
    void getAcceleration(double &ax_out, double &ay_out) const;
    void positionAt(double t, double &x_out, double &y_out) const;
    double distanceAt(const Point_18& other, double t) const;
    bool intersectsWith(const Point_18& other, double t1, double t2, double dt=0.01) const;
};

int countIntersections(const std::vector<Point_18>& points, double t1, double t2, double dt=0.01);

#endif
