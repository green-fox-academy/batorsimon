#include "Circle.h"

using namespace std;

Circle::Circle(int radius)
{
    this->radius = radius;
}

Circle::~Circle()
{
    cout << "Calculate another circle!" << endl;
}

float Circle::get_circumference()
{
    return (radius*2*3.14);
}

float Circle::get_area()
{
    return (radius*radius*3.14);
}

void Circle::print()
{
    cout << "The circle's radius : " << radius << endl;
    cout << "The circle's circumference: " << get_circumference() << endl;
    cout << "The circle's area: " << get_area() << endl;
}
