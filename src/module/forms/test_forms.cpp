#include "circle.h"
#include "triangle.h"
#include <vector>

int getLargestRadius(std::vector<Shape*> v)
{
    int largestRadius { 0 };
    for(const auto s : v)
    {
        Circle *dc {dynamic_cast<Circle*>(s)};
        if(dc)
        {
           largestRadius = std::max(dc->get_radius(),  largestRadius);
        }
    }
    return largestRadius;
}

void test_forms()
{
    Circle c{ Point{ 1, 2 }, 7 };
    std::cout << c << '\n';

    Triangle t{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }};
    std::cout << t << '\n';

    std::vector<Shape*> v{
        new Circle{Point{ 1, 2 }, 7},
        new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
        new Circle{Point{ 7, 8 }, 3}
    };

    // print each shape in vector v on its own line here
    for(const auto *s : v)
        std::cout << *s;

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

    // delete each element in the vector here
    for(const auto *s : v)
      delete s;
}
