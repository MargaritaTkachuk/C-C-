#ifndef RECTANGLE_H
#define RECTANGLE_H

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point A;
    Point B;
} Rectangle;

void inputPoint(Point *p);
void printPoint(Point p);
void inputRectangle(Rectangle *r);
void printRectangle(Rectangle r);

#endif
