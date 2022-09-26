#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "point.h"

class Circle : public Shape
{
private:
    Point m_center;
    int m_radius;
public:
    Circle(const Point& center, const int radius)
        :m_center{center}, m_radius{radius}
    {

    };

    std::ostream& print(std::ostream& out) const;

};

#endif // CIRCLE_H
