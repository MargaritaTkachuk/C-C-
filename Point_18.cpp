#include "Point_18.h"
#include <cmath>

Point_18::Point_18(double x0, double y0) : x0(x0), y0(y0), vx(0), vy(0), ax(0), ay(0) {}

void Point_18::setVelocity(double vx_, double vy_) { vx = vx_; vy = vy_; }
void Point_18::setAcceleration(double ax_, double ay_) { ax = ax_; ay = ay_; }

void Point_18::getVelocity(double &vx_out, double &vy_out) const { vx_out = vx; vy_out = vy; }
void Point_18::getAcceleration(double &ax_out, double &ay_out) const { ax_out = ax; ay_out = ay; }

void Point_18::positionAt(double t, double &x_out, double &y_out) const {
    x_out = x0 + vx * t + 0.5 * ax * t * t;
    y_out = y0 + vy * t + 0.5 * ay * t * t;
}

double Point_18::distanceAt(const Point_18& other, double t) const {
    double x1, y1, x2, y2;
    positionAt(t, x1, y1);
    other.positionAt(t, x2, y2);
    return std::sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

bool Point_18::intersectsWith(const Point_18& other, double t1, double t2, double dt) const {
    for(double t = t1; t <= t2; t += dt) {
        if(distanceAt(other, t) < 1e-6) return true;
    }
    return false;
}

int countIntersections(const std::vector<Point_18>& points, double t1, double t2, double dt) {
    int count = 0;
    for(size_t i=0; i<points.size(); i++) {
        for(size_t j=i+1; j<points.size(); j++) {
            if(points[i].intersectsWith(points[j], t1, t2, dt)) count++;
        }
    }
    return count;
}
