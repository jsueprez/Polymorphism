#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include "point.h"

class Triangle : public Shape
{
private:
    Point m_points[];
public:
    Triangle(const Point& p1, const Point& p2, const Point& p3)
        : m_points{p1, p2, p3}
    {
    };
};

#endif // TRIANGLE_H
