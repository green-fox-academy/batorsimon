#include <iostream>
#include <string>
#include "house.h"

using namespace std;

int main() {
    // The market price of the houses is 400 EUR / square meters
    // Make the get_price() function work
    // Create a constructor for the House class that takes it's address and area.

    house he("Andrassy 66", 349);
    he.print();

    return 0;
}
