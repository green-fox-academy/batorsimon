#ifndef HOUSE_H
#define HOUSE_H
#include <iostream>

using namespace std;

class house
{
    public:
        house(string address, unsigned int area);
        virtual ~house();
        get_price();
        void print();

    protected:

    private:
        string address;
        unsigned int area;
        unsigned int price;
};

#endif // HOUSE_H
