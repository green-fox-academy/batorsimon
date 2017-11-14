#include "house.h"

using namespace std;

house::house(string address, unsigned int area)
{
    this->address = address;
    this->area = area;
}

house::~house()
{
    cout << "Calculate another house's price!" << endl;
}


int house::get_price()
{
    price = area * 400;
    return price;
}

void house::print()
{
    cout << "The price of the house is: " << get_price() << endl;
}
