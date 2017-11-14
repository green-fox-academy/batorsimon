#include <iostream>
#include <string>

using namespace std;

class House {
  private:
    string address;
    unsigned int area;
    unsigned int price;
  public:
    unsigned int get_price() {
      this->price = area * 400;
      return this->price;
    }
    House(string address, unsigned int area){
        this->address = address;
        this->area = area;
    }
};

int main() {
  // The market price of the houses is 400 EUR / square meters
  // Make the get_price() function work
  // Create a constructor for the House class that takes it's address and area.

  House house = House("Andrassy 66", 349);
  cout << "The price of the house is: " << house.get_price() << endl;

  return 0;
}
