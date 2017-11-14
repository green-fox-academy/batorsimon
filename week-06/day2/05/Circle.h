#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>

using namespace std;

class Circle
{
    public:
        Circle(int radius);
        virtual ~Circle();
        float get_circumference();
        float get_area();
        void print();

    protected:

    private:
        int radius;
};

#endif // CIRCLE_H
