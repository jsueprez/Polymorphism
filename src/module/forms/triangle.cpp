#include "triangle.h"

std::ostream& Triangle::print(std::ostream& out) const
{
    return out << "Triangle(" << m_p1 << ", "
               << m_p2 << ", "
               << m_p3<< ")\n";
}
