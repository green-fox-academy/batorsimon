#include "Car.h"

using namespace std;

Car::Car(string type, int km)
{
    this->type = type;
    this->km = km;
}

Car::~Car()
{
    cout << "Calculate another car!" << endl;
}

int Car::run()
{
    int run_plus;
    cout << "Write down how many kilometers have you run: ";
    cin >> run_plus;
    return run_plus+km;
}

void Car::print()
{
    cout << "The car's name: " << type << endl;
    cout << "The car's km: " << km << endl;
    cout << "The car's km incremented with run: " << run() << endl;
}
